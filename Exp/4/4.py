def char_summary(word_list):
    summary = [" "]
    for word in word_list:
        for char in word:
            if char not in summary:
                summary.append(char)
    summary.sort()
    return summary


def dict_sort(word_list):
    char_sum = char_summary(word_list)
    max_len = max(map(len,word_list))
    for i in range(max_len,-1,-1):
        char_collector = {c: [] for c in char_sum}
        for word in word_list:
            char_collector[word[i] if i < len(word) else " "].append(word)
        word_list = []
        for collector in char_collector.values():
            word_list.extend(collector)
    return word_list


if __name__ == "__main__":
    word_list = [
        "apple",
        "egg",
        "ruby",
        "editor",
        "list",
        "apply",
        "data",
        "python",
        "application",
        "edit",
    ]
    print(dict_sort(word_list))
    # word_list.sort()
    # print(word_list)
