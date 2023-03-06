stack = []


# </keyword> 나오면 <keyword>사이 값들 stack에서 pop해서 뒤집고 다시 푸시

# TEST CASE 1
# <html><div>He<b style = color:blue;>llo</b> W<i>or</i>ld</div></html>
# <html><div>ld<i>ro</i>W <b style = color:blue;>oll</b>eH</div></html>

# TEST CASE 2
# <div>He<b style= 'asd'>llo</b></div>
# <div><b style = 'asd'>oll</b>eH</div>
def convertHtml(html):
    startIndex = -1
    endIndex = -1
    for i in range(len(html)):
        # < : 시작
        if html[i] == '<' and startIndex == -1: 
            startIndex = i
        # 키워드가 아닌 문자 입력값들일 때
        elif startIndex == -1 and html[i] != '<' and html[i] != '>':
            stack.append(html[i])
        # 닫는 키워드가 나오는 시점
        elif html[i] == '/':  # </
            endIndex = i
        # 닫는 괄호일 때, 앞에 /가 있으면 stack에서 pop하고 뒤집기
        # 앞에 /가 없으면 그냥 stack에 push
        elif html[i] == '>':
            if endIndex != -1:  # 끝나는 시점
                lastChunk = html[endIndex - 1:i + 1]  # </div>
                keyowrd = html[endIndex + 1:i] #<div 찾기
                newChunk = ''
                finish = False
                while stack:
                    if stack[-1][1:len(keyowrd) + 1] == keyowrd:
                        stack.append(stack.pop() + newChunk + lastChunk)
                        finish = True
                        break
                    else:
                        newChunk += stack.pop()
                if not finish:
                    stack.append(newChunk)
            elif startIndex != -1: # 앞에 /가 없고 startIndex 가 -1이 아니면 그냥 push
                chunk = html[startIndex:i + 1]
                stack.append(chunk)
            startIndex = -1
            endIndex = -1
    for ch in stack:
        print(ch, end='')


convertHtml("<html><div>He<b style = color:blue;>llo</b> W<i>or</i>ld</div></html>")
