#!/usr/bin/python3
""" a methode """


def canUnlockAll(boxes):
    """
    verifie si toutes les boîtes peuvent être ouvertes.

    Args:
        boxes (list of lists): chaque boîte contient des clés.

    Returns:
        bool: True si toutes les boîtes peuvent être ouvertes, sinon False.
    """

    n = len(boxes)
    unlocked = set([0])
    queue = [0]

    while queue:
        current_box = queue.pop(0)

        for key in boxes[current_box]:
            if key < n and key not in unlocked:
                unlocked.add(key)
                queue.append(key)

    return len(unlocked) == n
