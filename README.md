# Self_Study
## 목표
* 공부한 내용 기록
* 2문제 이상 알고리즘 문제 풀기

---
[6월](./2020/June)
---
## 7月

### 1日

- HTTP Method
    
    HTTP : HyperText Transfer Protocol의 약자로 HTML문서 등의 리소스를 전송하는 프로토콜이다.
    요청 방식으로는 여러 종류가 있지만 크롤링을 할때는 주로 get,post방식을 사용한다.
    Get 요청 : 데이터를 URL에 포함하여 전달(주로 리소스 요청에 사용)
    Post 요청 : 데이터를 Form data에 포함하여 전달(주로 로그인에 사용)

![http](./img/http.jpg)

-HTML

    HTML : Hyper Text Markup Language의 약자로 웹사이트를 생성하기 위한 언어로 문서와 문서가 링크로 연결되어 있고, 태그를 사용하는 언어이다.

    태그(Tag)란?
    HTML문서의 기본 블락으로 브라우저에게 어떻게 렌더링(화면에 표시)될지 전달한다.
    (ex. <태그명 속성1 = "속성값1" 속성2="속성값2">Value</태그명>
---

### 2日

Python collection types

- List
    
    여러개의 값을 담을 수 있는 데이터 구조로 C언어에서의 배열로 생각하면 이해하기 쉽다. 생성된 후에도 변경이 가능하다.
    초기화시 var_name = [] 형식으로 []안에 값을 넣어서 초기화 한다.  
    c언어에서와 차이점이 있다면 c언어에서는 배열에서 한번에 하나씩만 원소 선택이 가능하지만 python에서는 여러 원소를 선택이 가능하다. var_name[:]을하면 처음부터 끝까지 선택되고 var_name[1:]을하면 2번째 원소부터 마지막 원소까지 var_name[1:5]을하면 2번째 원소부터 5-1 즉 4번째 원소까지 선택하는등 슬라이싱이 가능하다. var_name[1:6:2]를하면 2번 원소부터 5번 원소까지 2칸씩 뛰므로 2,4번째 원소가 선택된다. 이처럼 python에서는 리스트에서 여러 원소를 본인이 원하는 방식으로 선택할 수 있다.   
    또 C언어에서는 배열 처음 선언한 크기보다 많은 원소를 넣으려면 크기를 키워줘야하는데 python에서는 var_name.append(value)을 하면 자동으로 크기가 커지며 해당 값이 마지막 원소로 삽입되며 var,var2라는 배열이 있으면 var.extend(var2) or var + var2 실행시 var에 var2의 원소들이 추가되는 등 배열 합치기도 가능하다.  
    var.append(var2)를 실행하면 var2의 원소들로 이루어진 리스트가 var의 새로운 원소로 추가된다. ([1,2,3,[2,3,4]])  
    insert함수를 통해 원하는 위치에 원하는 값을 추가하는 것도 가능하다. var.insert(1,40)하면 1번위치에 40의 값이 추가된다.  
    python에서는 배열 원소를 삭제도 가능하다. var.remove(value)를 하면 value와 일치하는 원소가 있을 시 해당 원소를 삭제한다.  
    var.pop()을 하면 배열의 마지막 값을 반환하고 지우는데 괄호 안에 숫자를 넣으면 해당 위치에 존재하는 함수를 반환하고 지운다.  
    in함수를 사용하면 해당 배열에 내가 찾는 값이 존재하는지도 알 수 있다. var = [1,2,3]일 때
    c = a in var를 사용하면 만약 a가 1,2,3중에 하나이면 var배열 안에 존재하므로 true가 반환되고 1,2,3이 아닌 다른 값인 경우 존재하지 않으므로 false가 반환된다.  
    sort함수를 통해 정렬도 가능하다. var.sort()를 사용하면 오름차순으로 정렬되고 var.sort(reverse=True)를 사용하면 내림차순으로 정렬할 수 있다.


- Tuple

    list와 같이 여러개의 값을 담을 수 있는 데이터 구조이나 생성된 후에는 변경이 불가능하다 c언어에서 const로 생각하면 될 것 같다.
    초기화시 var_name = () 형식으로 리스트와 초기화 방법은 비슷하지만 []가 아닌 ()로 선언하는것의 차이점이 있다. 또한 var_name = val1, val2등 ()를 생략하고 초기화할 수도 있다.

- Dictionary

    c에서 해시처럼 key와 value로 이루어진 데이터 구조로 var = {key1 : val1, key2 : val2}처럼 {}를 사용하여 초기화한다.
    Dictionary도 list처럼 합칠 수 있는데 update함수를 사용하면 된다. var.update(var2)를하면 var2의 key,val들이 var로 들어가지는데 이때 var와 var2의 키가 겹칠 경우 var2의 key:value값으로 들어가진다.  
    삭제의 경우는 var.pop[key] 또는 del var[key]를 하면 해당 key와 일치하는 item이 삭제된다.  
    clear함수를 사용하면 해당 변수내의 item이 모두 사라진다.  
    Dictionary에서도 in함수가 사용 가능한데 list에서와 차이점이 있다면 list에서 in함수는 O(n)의 시간이 걸리지만 Dictionary에서는 O(1)의 시간이 걸린다.  
    list(var.keys())와 list(var.values()) 함수를 통해 해당 변수의 key와 value들에만 접근할수도 있다.

- Set

    수학에서의 집합과 동일한 개념으로 dictionary에서 key만 활용하는 데이터 구조로 이해하면 쉽다.
    a = {1,2,3}, b = {2,3,4} 처럼 dictionary와 같이 {}를 사용하여 초기화한다.
    a.union(b)를 하면 a와b의 합집합인 원소들이 나오고 a.intersection(b)를 사용하면 a와 b의 교집합, a.difference(b)를 하면 a에서 b와의 차집합, a.issubset(b)를 하면 부분집합이 나온다.
---

### 3日

- 조건문

    c에서와 비슷하다. 조건이 참이면 해당 문맥안으로 들어가 실행하고 아니면 다음 코드를 진행한다.  
    c에서는 if, else if, else를 사용하지만 python에서는 if, elif, else를 사용한다. 그리고 다른점이 또 있는데 c에서는 {}를 사용하여 문맥을 구분하는데 python에서는 들여쓰기로 구별한다.

```
    C언어
    if(조건) {

    }
    else if(조건) {

    }
    else {

    }

    Python
    if 조건 :
        code // if문 code
    elif 조건 :
        code // elif문 code
    else :
        code // else code
    code // 조건문 밖에 있는 code
```

- 논리

    python에서는 논리 연산을 AND,OR,NOT을 사용하며 우선순위는 다음과 같다. NOT > AND > OR  
    조건1 OR 조건2 AND 조건3 을하면 조건1 OR (조건2 AND 조건3의 결과)가 된다. OR를 먼저하려면 (조건1 OR 조건2) AND 조건3을 하면 된다.
    사용법은 c에서와 같이 조건1 AND 조건2 같이 조건2개 사이에 논리 연산자를 사용하면 된다.

- 반복문

    python 반복문엔 c와 마찬가지로 while, for가 있다. 사용법도 위와 비슷하다.
    ```
    while 조건 :
        code

    for 조건 :
        code
    ```
    
    for의 사용법이 신기한데 아래와 같은 코드를 실행해보자
    ```
    a=[1,2,3,4]
    for i in a :
        print(i)
    ```
    실행하면 i가 a의 원소 첫번째부터 자동으로 변경되어 1,2,3,4가 출력된다. a가 문자열이라하면 문자열의 첫번째 문자부터 선택되는등 배열로 이루어진것을 순회하여 반복할 수도 있다.  
    또 단순히 몇번 반복하는지 등을 반복하려면 다음과 같이 하면 n번 반복된다(0~n-1)
    ```
    for i in range(n) :
        print(n) 
    ```
    
- 함수(Function)

    python에서 함수의 사용법은 다음과 같다.
    ```
    def fuc_name(p_param) :
        code
        return n,m
    ```
    c에서는 반환하려는 타입에 따라 함수 앞에 int, float등을 쓰지만 python에서는 def로 작성하고 반환하려는 변수를 return하면 끝이다. 또 c와 달리 반환값을 여러개 할수 있는데 위의 코드에서 a,b = fun_name을 하면 2개의 값이 반환되고 2개 이상도 가능하다.  
    이때 반환값이 없고 안에서 동작만 하는 경우를 매크로(macro)라고 부르는데 c에서의 void형 함수를 생각하면 된다. 인자를 안 넘기고 디폴트값을 사용할 수도 있는데 이때 인자들은 앞에서부터 적용되기때문에 디폴트값은 인자들중 뒤에 것부터 명시해줘야 한다.
    
---