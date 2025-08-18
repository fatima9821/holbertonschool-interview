#!/usr/bin/python3
"""
Recursive function that queries the Reddit API,
parses hot article titles, and prints a sorted count
of given keywords.
"""

import requests


def count_words(subreddit, word_list, after=None, word_count={}):
    """
    Recursively queries the Reddit API, counts keywords
    in hot article titles, and prints results.
    """
    if not subreddit or not word_list:
        return

    # Normaliser les mots-clés en minuscules
    if not word_count:
        word_list = [word.lower() for word in word_list]
        for word in word_list:
            if word not in word_count:
                word_count[word] = 0

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "holberton_count_script/1.0"}
    params = {"limit": 100, "after": after}

    try:
        response = requests.get(
            url, headers=headers, params=params, allow_redirects=False
        )
        if response.status_code != 200:
            return
        data = response.json().get("data")
        if not data:
            return

        # Parcours des titres
        for post in data.get("children", []):
            title = post.get("data").get("title").lower().split()
            for word in word_count.keys():
                word_count[word] += title.count(word)

        # Vérifier s'il y a encore une page
        after = data.get("after")
        if after:
            return count_words(subreddit, word_list, after, word_count)
        else:
            # Trier les résultats
            sorted_results = sorted(
                [(k, v) for k, v in word_count.items() if v > 0],
                key=lambda item: (-item[1], item[0])
            )
            for word, count in sorted_results:
                print("{}: {}".format(word, count))

    except Exception:
        return
