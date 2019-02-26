# Company: Palantir
# Question: Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a list of strings which represents each line, fully justified.
#
# More specifically, you should have as many words as possible in each line. There should be at least one space between each word. Pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.
#
# If you can only fit one word on a line, then you should pad the right-hand side with spaces.
#
# Each word is guaranteed not to be longer than k.

# Example:
"""
For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
"""
# Solution: Iterate over words and create the res by adding spaces in between

def justifyText(words, k):
    res = []
    while len(words) > 0:
        sum, idx = 0, 0
        curr_words = []
        for idx, word in enumerate(words):
            sum += len(word)
            curr_words.append(word)
            if k - sum - idx - 1 < 0:
                curr_words.pop()
                idx -= 1
                break

        words[0:idx + 1] = []

        # Add uniform spaces and append to res
        i = 0

        while len("".join(curr_words)) < k:
            curr_words[i] += " "
            i = (i + 1) % (len(curr_words) - 1)

        res.append("".join(curr_words))

    return res



if __name__ == "__main__":
    words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
    print(justifyText(words, 16))