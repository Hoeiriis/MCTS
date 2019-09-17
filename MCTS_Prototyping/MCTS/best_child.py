import numpy as np


def UCT_best_child(node, current_player, c=1 / np.sqrt(2)):
    child_scores = []
    child_visits = []
    for child in node.children:
        child_scores.append(node.score[current_player])
        child_visits.append(child.visits)

    best_child = np.argmax(np.divide(child_scores, child_visits) + \
                           c * np.sqrt(np.divide(2 * np.log(node.visits), child_visits)))

    return node.children[best_child]
