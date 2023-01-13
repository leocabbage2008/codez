"""Functions for creating, transforming, and adding prefixes to strings."""


def add_prefix_un(word):
    return 'un'+word


def make_word_groups(vocab_words):
    ans = pre = vocab_words[0]
    for word in vocab_words:
        if word != pre:
            ans += ' :: '+pre+word
    return ans


def remove_suffix_ness(word):
    vowels = ['a', 'e', 'i', 'o', 'u']
    word = word[0:word.index('ness')]
    if (word[-2] not in vowels) and (word[-1] == 'i'):
        return word[:-1]+'y'
    return word


def adjective_to_verb(sentence, index):
    return sentence.split()[index].replace('.', '')+'en'
