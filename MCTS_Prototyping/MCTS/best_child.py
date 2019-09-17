import numpy as np


def UCT_best_child(node, current_player, c=1 / np.sqrt(2)):
    child_scores = []
    child_visits = []
    for child in node.children:
        child_scores.append(child.score[current_player])
        child_visits.append(child.visits)

    best_child = np.argmax(np.divide(child_scores, np.asarray(child_visits)+0.000000001) + \
                           c * np.sqrt(np.divide(2 * np.log(node.visits), np.asarray(child_visits)+0.000000001)))

    return node.children[best_child]
