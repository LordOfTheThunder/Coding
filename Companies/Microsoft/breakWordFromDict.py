# Company: Microsoft
# Question: Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.
# Example:
"""
For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
"""
# Solution:

def breakWordFromDict(words, string):
    if not string:
        return []
    for word in words:
        if string.startswith(word):
            return [word] + breakWordFromDict(words, string[len(word):])

if __name__ == "__main__":
    print(breakWordFromDict(['quick', 'brown', 'the', 'fox'], "thequickbrownfox"))
    print(breakWordFromDict(['bed', 'bath', 'bedbath', 'and', 'beyond'], "bedbathandbeyond"))
