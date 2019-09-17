

def basic_backup(node, default_policy_score):
    ancestors = get_ancestors(node)
    for node in ancestors:
        node.visits += 1
        node.score[0] += default_policy_score


def backup_negamax(node, default_policy_score, current_player):
    ancestors = get_ancestors(node)

    for node in ancestors:
        node.visits += 1
        node.score[current_player] += default_policy_score

        default_policy_score = -1*default_policy_score
        current_player = 0 if current_player == 1 else 1


def get_ancestors(node):
    return _get_ancestors(node, [])


def _get_ancestors(node, ancestor_list):
    ancestor_list.append(node)
    parent = node.parent

    if parent is not None:
        _get_ancestors(parent, ancestor_list)

    return ancestor_list
