#!/usr/bin/python3


"""Determines if all boxes can be opened."""


def canUnlockAll(boxes):
    """Return True if all boxes can be opened, else return False."""
    unlocked = {0}
    keys = [0]
    while keys:
        new_keys = []
        for key in keys:
            for new_key in boxes[key]:
                if new_key not in unlocked and new_key < len(boxes):
                    unlocked.add(new_key)
                    new_keys.append(new_key)
        keys = new_keys
    return len(unlocked) == len(boxes)