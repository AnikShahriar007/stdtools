# C stdtools Readme #

**Name         :** stdtools  
**Version      :** 0.6.4.5  
**Contributors :** AnikShahriar007  

**stdtools** is a custom C library containing a number of useful c functions.

## What is 'stdtools'? ##

**stdtools** is a custom **C** library. Many of us C programmers find functions we need to use in many programs. It's a boring work copying and writing the same functions over and over again. So, to solve this, I've made a custom library that every C programmer can use. It contains a number of common and useful C functions.

**stdtools** is made open-source for the help of other programmers. Feel free to use it, and of course contributing in it. If you can upgrade any function, modify it to run in efficient ways, please go ahead. The more function it contains, the better for others.

## Changelog ##

  ### 0.6 ###
  * Added new function 'flcat'
  * Modified function 'flcopy' to use 'flcat' and 'fldelete'
  * Added new function 'dtos'
  * Modified function 'itos' by changing variable name to 'number'
  * Added new function 'power'
  * Added new function 'flpow'
  * Added new function 'factorial'
  * Added new function 'isprime'
  * Added new function 'degtorad'
  * Added new function 'radtodeg'
  * Added new function 'sinx'
  * Added new function 'cosx'
  * Added new function 'tanx'
  * Added new function 'dectobin'
  * Added new function 'dectooct'
  * Added new function 'dectohex'
  * Added new function 'bintodec'
  * Added new function 'octtodec'
  * Added new function 'hextodec'
  * Added new function 'strinput'
  * Added new function 'intinput'
  * Added new function 'flinput'
  * Fixed bug in function 'reverse'
  * Modified function 'wordcount'
  * Changed function name from 'flswap' to 'dblswap'
  * Modified 'dblswap' to swap doubles instead of floats
  * Added new function 'resize_window'
  * Added new function 'set_title'

  ### 0.5 ###
  * Added new function 'flmerge'
  * Removed use of 'error' function from 'flwrite' and 'flappend'
  * Changed return type of 'flwrite' and 'flappend' to int from void
  * Modified 'flread' to use 'flreadline'
  * Modified 'flreadline' to read line using fgets
  * Reorganized functions according to task
  * Changed name of function 'open_url' to 'openurl'
  * Changed name of function 'catch_signal' to 'catchsignal'
  * Added new function 'replace'
  * Used variable 'str' to create duplicate of text with strdup in 'uppercase'
  * Used variable 'str' to create duplicate of text with strdup in 'lowercase'
  * Used variable 'str' to create duplicate of text with strdup in 'reverse'
  * Used variable 'str' to create duplicate of text with strdup in 'replace'
  * Added new function 'charswap'
  * Modified 'reverse' to use 'charswap'
  * Added new function 'substring'
  * Renamed 'infile' to 'flsearch'
  * Added new function 'fldelete'
  * Added new function 'flcopy'
  * Added new function 'flmove'
  * Optimized 'flcopy' by removing extra memory allocation and freeing memory
  * Optimized 'flreadline' by removing extra memory allocation and freeing memory
  * Optimized 'flread' by freeing memory
  * Optimized 'flsearch' by freeing memory
  * Modified 'flsearch' to use 'flreadline'
  * Optimized 'flmerge' by removing extra memory allocation and freeing memory
  * Optimized 'strsort' by removing extra memory allocation
  * Optimized 'strswap' by freeing memory
  * Added new function 'casechange'
  * Added new function 'wordcount'
  * Added new function 'charcount'
  * Added new function 'charoccur'
  * Added new function 'fllinecount'

  ### 0.4 ###
  * Added new function 'tstruct'
  * Added new function 'getsec'
  * Added new function 'getmin'
  * Added new function 'gethour'
  * Added new function 'getmonth'
  * Added new function 'getyear'
  * Added new function 'getwday'
  * Added new function 'getmday'
  * Added new function 'getyday'

  ### 0.3 ###
  * Added new function 'strswap'
  * Added new function 'intswap'
  * Added new function 'flswap'
  * Modified 'strsort' function to use 'strswap'
  * Closed file at end of 'infile'

  ### 0.2 ###
  * Added error check with memory allocation and file io
  * Fixed char pointer (char \*) allocation
  * Added new function 'failure'
  * Deleted unnecessary comments

  ### 0.1 ###
  * First attempt to stdtools. 

