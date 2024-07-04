#!/usr/bin/python3

def canUnlockAll(boxes):

    unlocked = set([0])
    
    queue = [0]
    
    while queue:
        current_box = queue.pop(0)
        for key in boxes[current_box]:
            if key not in unlocked and key < len(boxes):
                unlocked.add(key)
                queue.append(key)
    
    return len(unlocked) == len(boxes)