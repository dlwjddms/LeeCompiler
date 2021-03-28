# LeeCompiler
# Copy of Compiler Term project                                   1. Lexical analyzer

### 20162191 이상진

### 20181149 이정은

# **[ Index ]**

# 1. **Organize the lexical specification based on understanding the task manual**

# 2. **Define Token (name, value of each token)**

# 3. **Regular Expression for each token (specifying each token)**

# 4. **NFA for each token**

# 5. **DFA for recognizing token**

# 6. **Implementation**

# 

# 1. **Lexical Specification**

Based on the task manual, identify and organize the conditions that each token must satisfy. The lexical analyzer in this project is only satisfied with the following conditions.

## **Variable Type**

- int
- char
- bool
- float

This token need to satisfy the above four strings.

## **Signed Integer**

- Single zero digit

     → accepted single ‘0’.

     → If '00', two '0' '0' are recognized.

- Non empty digit starting from non zero digit

    → If '012', distinguish between '0' and '12'.

- A negative integer with non empty digit using non zero digit

    → When '-0' , has to be '-'and'0'

    +) For negative numbers, for the sake of differentiation from subtraction, '-1' is recognized as negative; – 1 (when WS are behind -) is recognized as subtraction.

At this time, it can be seen that the integer and float must have a higher priority than the operator.

## **Literal String**

- The corresponding value between ' " ' and'  "  'should be included.

    → ERROR : If ' " ' ends unmatched or the number of ' " '  at the end is odd.

- There is only digit, english letter and blank between ' " ' and ' " '  .

    → ERROR : There is only digit, english letter and blank between ' " '  and' " ' .

    → ERROR : ' " ' comes right after ' " '

    →Remove the ' " ' and ' " ' indicating the string section when placing it in the token value and load the rest.

## **Boolean**

- true
- false
- TRUE
- FALSE

This token need to satisfy the above four strings.

## **Float**

- ‘**.**’ Appears only once.

    → ERROR : If there are more than two ' . ' 

    → (e.g. 1.223.4 :  1.223 (o) and .4(x))

    → (e.g. 12.34. : 12.34(o) and . (x))

- **integer part )** single 0 digit or no empty sequence start from non zero

    →Separate '[00.xxx](http://00.xxx/)' with integer '0' and '[0.xxx](http://0.xxx/)'

    → Separate '[01.xxx](http://01.xxx/)' with '0' and '[1.xxx](http://1.xxx/)'

    → Separate '-[01.xxx](http://01.xxx/)' with'-', '0' and '[1.xxx](http://1.xxx/)'

- **fraction part )** single 0 digit or no empty sequence

    → If 'xx.00' , divide it into 'xx.0' and integer '0'

    → If ‘ xx.12300’ , divide it into ‘xx.123’and integer  ‘0’ , ’0’

    +) It can be seen that the float is in the presence of the ' . ' . Therefore, the priority of the float is higher than that of the integer.

    +) We decided to accept '-0.0' through the condition of float satisfaction.

## **KeyWord**

- if
- else
- while
- for
- return

This token need to satisfy the above five strings.

## Identifier

- A nonempty sequence of English letters, digits and _
- must start with English letter or _

    +) Identifier has less priority then Boolean, KeyWord, and Variable type

## Operators

- Arithmetic operators: +, -, *, /
- Bitwise operators: <<, >>, &, |
- Assignment operator: =
- Comparison operators: <, >, ==, !=, <=, >=

    +) Bitwise operators priority higher than Comparison operators. If not, input string like '<<' will be detect as two sequence of comparison operator '<'
    (same situation occurs when '>>' as string input )

    +) priority of Assignment operator is lower than comparison operators. If not, input string like '==' will be detect as two sequence of assignment operator '='

## Special symbols

- Parentheses symbols: (, )
- Brace symbols: {, }
- seperating symbol: ,
- terminating symbol: ;

## White space

- \n, \t, blanks

# 2. **Define Token**

We will define token in terms of 'Token Name' and 'Token Value'.

The table below show our token definition.

[token table](https://www.notion.so/7c9fe0b066d0404eacb3da27b78091c8)

# 3. **Regular Expression for each Token**

This chapter defines regular expressions for each tokens to specify pattern of tokens.
Regular expression below erase the ambiguity of recognizing token and make clear grammar for regular language. These regular expressions are based on lexical specifications of term project 1.

We define  this regular expression based on lexical specification above (section 1).

- **Variable Type.**

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled.jpeg)

- **Boolean**

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%201.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%201.jpeg)

- **Literal String**

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%202.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%202.jpeg)

- **Signed Integer**

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%203.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%203.jpeg)

- **Float**

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%204.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%204.jpeg)

- **Keyword**

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%205.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%205.jpeg)

# 4. **NFA for each token**

This chapter shows NFA for each token from defined regular expressions above.
These NFAs will be used for creating DFAs, and we used Thompson Algorithm for this NFA(which recommended in compiler lecture).

We define this NFA based on Regular expression above (section 3).

- **Variable Type**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%206.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%206.jpeg)

- **Signed Integer**

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%207.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%207.jpeg)

- **Literal String**

- **Boolean**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%208.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%208.jpeg)

- **Float**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%209.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%209.jpeg)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2010.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2010.jpeg)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled.png)

- **Keyword**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2011.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2011.jpeg)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%201.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%201.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%202.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%202.png)

- Bitwise operators

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%203.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%203.png)

- Assignment operator

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%204.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%204.png)

- Termination symbol

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%205.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%205.png)

- Comparison operators

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%206.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%206.png)

- Brace symbol

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%207.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%207.png)

- Parentneses symbol

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%208.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%208.png)

- Seperation symbol

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%209.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%209.png)

- white space

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2010.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2010.png)

# 5. **DFA for recognizing token**

This chapter shows DFA for recognizing each token from defined NFA above. Below DFAs are used to implement our lexical analysis We use subset Algorithm for this DFA.

We define  this DFA based on lexical specification above (section 4).

- **Variable Type**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2012.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2012.jpeg)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2013.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2013.jpeg)

- **Signed Integer**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2014.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2014.jpeg)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2015.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2015.jpeg)

- **Literal String**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2011.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2011.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2016.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2016.jpeg)

- **Boolean**

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2017.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2017.jpeg)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2018.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2018.jpeg)

- **Keyword**

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2012.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2012.png)

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2019.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2019.jpeg)

- **Float**

1)  **Left**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2020.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2020.jpeg)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2021.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2021.jpeg)

2) **Right**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2013.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2013.png)

3) **Total**

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2022.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2022.jpeg)

- Identifier

- Arithmetic operators

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2014.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2014.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2015.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2015.png)

- Comparison operators

- Assignment symbol

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2016.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2016.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2017.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2017.png)

- Termination symbol

- Brace symbol

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2018.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2018.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2019.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2019.png)

- seperation symbol

- white space

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2020.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2020.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2021.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2021.png)

# 6. **Implement**

## overall procedure

## Algorithm

This chapter describes the implementation of the lexical analyzer. 

We used C language as the implementation language of the project and implemented and tested the tasks in the Unix-based operating system.

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-07__12.11.33.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-07__12.11.33.png)

The above algorithm is the overall operational algorithm of our project based on what was introduced in class.

The 'left' represents the last place where the test was conducted and the beginning of the new test, and the 'right' refers to the accepted last place where the new test was taken immediately.

If there is a part corresponding to the language of the token in the array 'a', update the 'right'  and cut the part into the symbol table.

## Introduction of files

- **main.c**  : This file has functions that represent our overall algorithm. That is, call the function that inits the token tree for later comparison and call the functions that recognize the tokens based on the token tree according to the priority. And also in main function, we do file I/O to get an input file and to make an output file.
- **lexicalAnalyzer.c/lexicalAnalyzer.h** : This file classifies tokens that meet the conditions by comparing them while touring the appropriate token tree. In addition, if several errors are found that violate the conditions, the error location is printed and the execution is stopped using an assertion. Also, in some tokens like integer, float, string some alphabets can be grouped, by making a function that converts them into one letter we could make token recognization easier.
- **initTree.c/initTree.h** : There is a function that creates a tree for each token that is used to compare the tokens later. At this time, a pointer is also declared for each tree as global variables that point to the corresponding tree, making it easier to use the tree.

## Introduce of functions for each file

### 1.  main

- Used Data Structure

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__7.44.52.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__7.44.52.png)

'symbolTable' structure is node for storing each token's name and value. 

Because of this, each token is connected in linked list. 

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__7.47.40.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__7.47.40.png)

We tour the DFA trees to find one token. Each time the tree is checked, 'lexeme' structure stores the acceptance of the token, the length of the token when it is accepted, and the token name.

- main

The main function follow the sequence below

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2022.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2022.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2023.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2023.png)

1. check whether input file is valid is not print an error message and assert the process
2. Open the file and read the contents of the file one line at a time and combine them into a string.
3. Send the final string to lexicalAnalyzer function to get making symbolTable linked list.
4. Create and open a file with the same name as the input file. If the file is properly created and opened, write each node of the symbolTable to the file. (Token Name and Value)
5. After the valid tokens are stored in a output file, check whether all the strings are checked properly with 'success' variable.
(The lexical analyzer could stop due to invalid alphabet)
- lexicalAnalyzer

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2024.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2024.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2025.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2025.png)

(A code with a similar shape was omitted for now.)

1. Declare the 'line' variable for storing the position in the input file, head of the symbol table, and 'end' variable for the length of the input string.
2. Declare lexeme variable and store the line variable into it.  
3. Check the input string have tokens by comparing it with the token trees. If the tokens are valid move to insert part by using goto statement. 
If not, go to the next token tree. 
But if there is no valid token until every token tree used, set success variable to true, and break the while loop.
4. The insert section updates the right variable that indicates the last location of the accepted token. After declaring a node that forms a new symboltable, store the name of the token stored in the lexme structure on the node.
After store some part of the string as long as the length of len variable stored in the lexme structure on the node.
5. Push the node to the symbolTable.

6. Update the left variable which indicates the starting point of the token for finding new token after this.

7. Repeat 2-6 until the right variable meet the end variable .

### 2. initTree

- Used Data Structure

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.15.50.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.15.50.png)

'token Tree' is a state that consist the tree of the token.

'alpha' represents the alphabet needed to come to this state.

'ret ' represent whether this is final state or not

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.20.54.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.20.54.png)

Those are the variables that point to each token Tree.

- initTree

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.20.19.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.20.19.png)

This function call every functions that make token tree.

This functions has to be called before recognizing the tokens.

- init functions

Since there are 15 functions that have the same rules for making token trees, we will introduce only a few. 

[ initString ]

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.51.27.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.51.27.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2023.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2023.jpeg)

Out tree is made based on our DFA.

Above figure is visualization  of the code on the left side.

If the number of states that have passed a certain input value is the same, we call this has the same level .

Link as sibling if the level of the states are same.

And if certain inputs come in and you can go to a particular state, then lead to a child relationship. Put that certain input to particular state. If the state is not final state set ret variable as false.

[ initInteger]

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.52.47.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__9.52.47.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2024.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2024.jpeg)

This token tree is created in the same way as above.

[initBoolean]

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__6.06.57.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__6.06.57.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2025.jpeg](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2025.jpeg)

The rest of the code is omitted because it has the same rules as the function above.

[initIdentifier]

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2026.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2026.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2027.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2027.png)

### 3. lexicalAnalyzer

- Used Data Structure

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__7.47.40.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-08__7.47.40.png)

We tour the DFA trees to find one token. Each time the tree is checked, 'lexeme' structure stores the acceptance of the token, the length of the token when it is accepted, and the token name.

- converted

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__4.53.19.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__4.53.19.png)

    The main function of this function is to return a certain character by changing them to their corresponding value. For example, if the state of the integer's token tree changes because of the alphabets 1,2,3,4,5,6,7,8,9 from A to B, those could be defined as the 'n' to enhance the convenience of storage and comparison.

    Recognizing that this function is available, it was referred to when saving the token tree. Later, when comparing certain characters with the token tree, we made it to verify that certain characters match the value of the tree through that function.

- Recognizing functions

Since there are 15 functions that have the same rules for recognizing tokens, we will introduce only a few. 

[Float]

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2028.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2028.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2029.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2029.png)

1. First, bring the variable that points to the float's token tree and declare the t_count, which stores the last true state.

2. To compare the input string with the token tree, convert it to an appropriate representative character using the convert function.

3. Compare the transformed character with the alpha variable in the token tree.

4. If the comparison matches, escape the while loop, but if not, move to the sibState.

5. Repeat steps 2-4 until you escape the while loop. However, if there is no more sibState to go (tmp = NULL), also escapes the while loop.

6. Increase the count variable that stores the length of the string that has been inspected so far and check whether the while loop has escaped because it is ' tmp = = NULL' . In this case, it means that there is no more alphabet satisfying the tree, escape the entire while loop .

7. If not , store the the reset value of the current state and count value to the lexeme structure (lex), which stores the information of the strings currently being examined.

8. Now you now that there is currently a character that satisfies the state of the tree. Then to check the next character, move to the current state's child state.

9. Repeat steps 2-8 until (tmp == NULL) when the tree no longer has a childstate to go.

10. For error handling if the converted character for error handling is dot (.), and the number does not immediately follow (n or z) then end the run. It also ends the run if the first character is dot (.). Make sure that the left and right sides are not empty based on dot (.).

11. Finally, for situations such as 'xx.xx00', to recognize it as 'xx.xx'. It is done when the alpha in the last state is zero and the t_count is not zero, which records the position, when state that matches the value of the character being examined is the final state.

12. If not 11th situation and  the last saved state is true, save the token name to lex and return the true.

[variable]

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2030.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2030.png)

1. First, bring the variable that points to the variable's token tree and declare the t_count, which stores the last true state.

2. In this function we don't use convert function. So just compare the character with the alpha variable in the token tree.

3. If the comparison matches, escape the while loop, but if not, move to the sibState.

4. Repeat steps 2-3 until you escape the while loop. However, if there is no more sibState to go (tmp = NULL), also escapes the while loop.

5. Increase the count variable that stores the length of the string that has been inspected so far and check whether the while loop has escaped because it is ' tmp = = NULL' . In this case, it means that there is no more alphabet satisfying the tree, escape the entire while loop .

6. If not , store the the reset value of the current state and count value to the lexeme structure (lex), which stores the information of the strings currently being examined.

7. Now you now that there is currently a character that satisfies the state of the tree. Then to check the next character, move to the current state's child state.

8. Repeat steps 2-8 until (tmp == NULL) when the tree no longer has a childstate to go.

9. For case like 'int123_ab', this case have to be identifier. Therefore check the next character of the accepted token, and if there is number or '_' or letter we return false.

10. If not, and the last saved state is true, save the token name to lex and return the true.

[string]

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2031.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2031.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2032.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2032.png)

This function comes from isInteger function. That is, while checking character in isInteger and when we find dot '.' we move to this function.

1. First, bring the variable that points to the string's token tree and declare the eHandler, which stores the presence or absence of double quotes, and the numQ variables that store the number of double quotes .

2. To compare the input string with the token tree, convert it to an appropriate representative character using the convert function.

3. Compare the transformed character with the alpha variable in the token tree.

4. If the comparison matches, escape the while loop, but if not, move to the sibState.

5. Repeat steps 2-4 until you escape the while loop. However, if there is no more sibState to go (tmp = NULL), also escapes the while loop.

6. Increase the count variable that stores the length of the string that has been inspected so far and check whether the while loop has escaped because it is ' tmp = = NULL' . In this case, it means that there is no more alphabet satisfying the tree, escape the entire while loop .

7. If not , store the the reset value of the current state and count value to the lexeme structure (lex), which stores the information of the strings currently being examined.

8. Now you now that there is currently a character that satisfies the state of the tree. Then to check the next character, move to the current state's child state.

9. Repeat steps 2-8 until (tmp == NULL) when the tree no longer has a childstate to go.

10. For error handling, when the numberQ is 1, i.e., when the current location is in the string, the execution stop if there is a value other than number, english letter, and blank. Also, even if the first double quotation mark comes and right after that the second double quotation mark comes, the execution stop, and finally the execution stop if eHandler is true but numQ is not 2 which means that " has no pair and never ends.

11. If the last saved state is true, save the token name to lex and return the true.

# 7. Test

## Environment variable setting (global)

- Our scheme is implemented and tested on Unix based OS. (Mac, Linux etc..)
- And we've changed some environment for the convenience of the execution.
    1. Open the ~/.bashrc file (vi ~./bashrc)
    2. Add the path (export PATH=$PATH:.)
    3. Type shell command to load the changes (source ~/.bashrc)

    above procedure enables executing program without ' ./ '(present directory) .

## Test command

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__5.40.14.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__5.40.14.png)

By making Makefile we set the execution file name 'lexical_anaylzer'

And if the environment setting is done (modifying ~/.bashrc file) the command might be :

→ lexical_anaylzer [file_name]

If not :

→  ./lexical_anaylzer [file_name]

## Test case

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.46.37.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.46.37.png)

### 1. proper case

```c
int main(){
	printf("Hello compiler 1");
	float a, b;
	a = 3.1415926535897932;
	b = -0.014;
	
	int c;
	c = (int)(a *b);
	c = -5.34

	bool =K;
	K = true;
	
	if(a >= b){
		return 0;
	}
	for(int i = 0; term | (x & y); i+1){
		_add_on(polynomial x, polynomial y);
	}

	return -1;
}
```

→ result of proper case (test.out file)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.53.51.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.53.51.png)

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.55.19.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.55.19.png)

[]()

### 2. special case

[integer]

- 000

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.49.38.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.49.38.png)

- -0123

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.50.14.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.50.14.png)

[float]

- -00.234

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.50.52.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.50.52.png)

- -12.33300

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.51.28.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.51.28.png)

[comparsion]

- ===

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.52.46.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__9.52.46.png)

[identifier]

- int123

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.09.09.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.09.09.png)

- ifabc12

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.09.51.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.09.51.png)

### 3. error checking

[float]

- 123.45.5

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.10.30.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.10.30.png)

- 123..45

    ![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.11.06.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.11.06.png)

[string]

- ""

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2033.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/Untitled%2033.png)

- "123"34"

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__11.05.15.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__11.05.15.png)

- "123* "

![Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.25.15.png](Copy%20of%20Compiler%20Term%20project%201%20Lexical%20analyzer%203959b52948564ebd940a79c09106986f/_2020-05-09__10.25.15.png)

## All test cases from lecture announcements are tested and well functioning.

## thank you for reading this term project report.

## hello ,thank you for reading this term project report.

kefelfjslkffjkkeint jfs
