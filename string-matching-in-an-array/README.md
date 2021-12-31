[Discussion Post (created on 31/11/2021 at 17:1)](https://leetcode.com/problems/string-matching-in-an-array/discuss/1658277/C%2B%2B-oror-EASY-TO-UNDERSTAND-oror-SIMPLE)  
[Discussion Post (created on 7/9/2021 at 0:49)](https://leetcode.com/problems/string-matching-in-an-array/discuss/1507089/C%2B%2B-oror-EASY-TO-UNDERSTAND-oror-short-and-Efficient)  
<h2>1408. String Matching in an Array</h2><h3>Easy</h3><hr><div><p>Given an array of string <code>words</code>. Return all strings in <code>words</code> which is substring of another word in <strong>any</strong> order.&nbsp;</p>

<p>String <code>words[i]</code> is substring of <code>words[j]</code>,&nbsp;if&nbsp;can be obtained removing some characters to left and/or right side of <code>words[j]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["mass","as","hero","superhero"]
<strong>Output:</strong> ["as","hero"]
<strong>Explanation:</strong> "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["leetcode","et","code"]
<strong>Output:</strong> ["et","code"]
<strong>Explanation:</strong> "et", "code" are substring of "leetcode".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["blue","green","bu"]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code> contains only lowercase English letters.</li>
	<li>It's <strong>guaranteed</strong>&nbsp;that <code>words[i]</code>&nbsp;will be unique.</li>
</ul>
</div>