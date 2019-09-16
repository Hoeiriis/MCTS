import numpy as np

class InvalidMoveException(Exception):
    pass

class StateNotTerminalException(Exception):
    pass

class Board:
    player_turn = 1
    board = None
    game_finished = False
    winner = 0
    
    # Kind of a hackish way to check for wins
    winning_states = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]

    def __init__(self):
        self.reset_game()        
    
    def reset_game(self):
        self.board = self.start_state()
        self.player_turn = 1
        self.game_finished = False
        self.winner = 0
        
    @staticmethod   
    def create_board_from_state(state):
        board = Board()
        board.board = state
        board.update()
        even = lambda x: x % 2 == 0 
        board.player_turn = 2 if even((state == 0).sum()) else 1
        
        return board
    
    def start_state(self):
        return np.zeros((3,3)).astype(int)
    
    def get_valid_child_states(self, state):
        board = Board.create_board_from_state(state)
        
        return board.future_states()
    
    def evaluate_terminal_state(self, state):        
        board = Board.create_board_from_state(state)
        
        if not board.game_finished:
            raise StateNotTerminalException(f"State not terminal:\n{Board.draw_board(state)}")
            
        return board.get_reward()
        
    def get_reward(self):
        # don't recompute if result is known
        if self.winner is not 0:
            return 1 if self.winner is 1 else -1
        
        board = self.board.ravel()
        for state in self.winning_states:            
            if (board[state] == 1).all():
                return 1
            if (board[state] == 2).all():
                return -1
        
        # draw
        return 0
    
    def is_finished(self):
        """
        return False if not finished, 1 if player 1 won, 2 if player 2 won
        """
        
        if len(self.valid_moves()) is 0:
            return True
        
        if self.get_reward() is not 0:
            return True
                
        return False
    
    def update(self):
        if self.is_finished():
            reward = self.get_reward()
            if reward is 1: self.winner = 1
            if reward is -1: self.winner = 2
            self.game_finished = True            
        
    
    def valid_moves(self):
        """
        returns a list of valid moves
        """
        if self.game_finished:
            return []
        x, y = np.where(self.board == 0)
        return list(zip(x,y))                
    
    def is_move_valid(self, action):            
        return action in self.valid_moves()
    
    def board_state(self):
        return self.board
    
    def future_states(self):
        states = []
        for move in self.valid_moves():
            state = self.board.copy()
            x, y = move
            state[x,y] = self.player_turn                   
            states += [state]
            
        return np.asarray(states)
    
    def move(self, player, action):        
        if not self.is_move_valid(action):
            raise InvalidMoveException(f"Board slot {action} is not valid")
            
        if not self.player_turn == player:
            raise InvalidMoveException(f"Player {player} tried to move, but it's player {self.player_turn}'s turn")
            
        if self.game_finished:
            raise InvalidMoveException("Game has finished. Call reset_game to start a new game.")
        
        x, y = action
        self.board[x, y] = player
        
        self.update()
        self.player_turn = 2 if player == 1 else 1        
        
    
    def __str__(self, state=None):
        return Board.draw_board(self.board)

    @staticmethod
    def draw_board(board):        
        result = "-------------\n"
        symbol_table = {0: '   ', 1: ' X ', 2: ' O '}
        
        for row in board:
            result += "|"
            for value in row:
                symbol = symbol_table[value]
                result += symbol + '|'
            result += '\n'
            result += "-------------\n"
            
        return result
    
    def __repr__(self):
        board = str(self)
        
        result = board
        
        done = self.is_finished()
        if done:
            winner = self.winner
            result += f"\nGame finished."
            result += f"\nPlayer {winner} wins!"
        
        return result
        
    
    