# Today I Learn

## 목표

- 공부한 내용 기록
- 2문제 이상 알고리즘 문제 풀기

## 10 月

### 13 日

- Moment.js

  `Moment.js`는 자바스크립트에서 `dates`를 다루기 위한 라이브러리로 깔끔하고 간결한 API를 이용해 날짜와 시간을 분석, 검증, 조작, 표시할 수 있다

  - 시작하기

    Moment.js는 [moment.js 홈페이지](https://momentjs.com/)에서 무료로 다운로드해서 사용할 수 있다 또한 명령어를 통해서도 설치할 수 있다

    ```sh
    # node
    npm install moment

    # yarn
    yarn add moment

    #bower
    bower install moment --save

    ...
    ```

    설치 후 `require()` 하면 아래와 같이 사용할 수 있다

    ```sh
    const moment = require('moment');
    const today = moment();
    console.log(today.format());
    # Moment<2021-10-13T16:57:28+09:00>
    ```

  - Date 형식 지정 : Date Formatting

    Moment.js는 date를 어떤 형식으로든 간단하게 변환할 수 있게 format()함수를 제공한다

    ```sh
    const moment = require('moment');
    const today = moment();
    console.log(today.format()); # 2021-10-13T16:57:28+09:00
    console.log(today.format('YYYY-MM-DD')); # 2021-10-13
    console.log(today.format('YYYY-MMM-DD')); # 2021-Oct-13
    ```

  - Date 검증 : Date Validation

    Moment.js가 크게 단순화한 또 다른 작업은 date 검증으로, 유혀성 검증을 수행하려면 원하는 date 형식과 함께 날짜 문자열을 `moment` 객체에 전달한 후 `isValid()` 메소드를 호출하면 결과값으로 유효하면 `true`를 아니면 `false`를 반환한다

    ```sh
    console.log(moment('2021-10-13','YYYY-MM-DD')) # true
    console.log(moment('not-a-date','YYYY-MM-DD')) # false
    ```

    주의사항으로 Moment는 date 형식의 일부분만 작업할 수 있는 가능성을 제공하기 때문에 예상과 다른 결과가 반환될 수 있는데 이런 상황을 피하기 위해 3번째 인자로 `true`를 전달하면 Moment를 엄격 분석모드로 설정할 수 있다

    ```sh
    console.log(moment("2021 this year is bad", "YYYY-MM-DD").isValid()) # true
    console.log(moment("2021 this year is bad", "YYYY-MM-DD", true).isValid()) # false
    ```

    `moment()`가 반환하는 객체에는 다양한 flag들이 있다

    - overflow : overflow가 발생했을 때(13월 or 32일 등 존재하지 날)
    - invalidMonth : month가 유효하지 않을 때(영어에 오타가 나거나 존재하지 않는 달력일 경우 ex.Jauunary, error 등)
    - empty : 입력된 date가 분석 가능한 어떤 것도 포함되지 않을 때
    - nullnput : 입력된 date 값이 `null`일 때

  - Date 조작하기 : Date Manipulating

    `moment` 객체를 조작하는 다양한 옵션들이 있는데 대표적으로는 `add()`와 `subtract()`가 있다

    ```sh
    #add
    moment().add(7, 'days' or 'd') # 현재 날짜에 7일을 더한다
    # today : 2021-10-13T17:10:15+09:00
    # return : 2021-10-20T17:10:15+09:00
    moment().add(7, 'months' or 'M') # 현재 날짜에 7개월을 더한다 M 대신 m을 쓰면 분이 더해진다
    # today : 2021-10-13T17:10:15+09:00
    # return : 2022-05-13T17:10:15+09:00
    moment().add(7, 'years' or 'y') # 현재 날짜에 7년을 더한다
    # today : 2021-10-13T17:10:15+09:00
    # return : 2028-10-13T17:10:15+09:00

    #subtract
    moment().subtract(7, 'days' or 'd') # 현재 날짜에 7일을 뺀다
    # today : 2021-10-13T17:10:15+09:00
    # return : 2021-10-06T17:10:15+09:00
    moment().subtract(7, 'months' or 'M') # 현재 날짜에 7개월을 뺀다
    # today : 2021-10-13T17:10:15+09:00
    # return : 2021-03-13T17:10:15+09:00
    moment().subtract(7, 'years' or 'y') # 현재 날짜에 7년을 뺀다
    # today : 2021-10-13T17:10:15+09:00
    # return : 2014-10-13T17:10:15+09:00
    ```

  - Date 비교하기 : Date Comparing

        현재 시점으로부터의 시간 차이를 계산하기 위해서는 `fromNow()`메소드를, 임의의 두 date를 비교하기 위해서는 `from()`, `diff()` 메소드를 사용하면 된다

        ```sh

        # 오늘과 비교하기
        moment('2021.10.11','YYYY.MM.DD').fromNow();
        # 2 days ago
        moment('2021.10.11','YYYY.MM.DD').fromNow(true); # true를 인자로 넘기면 접미사를 없앨 수 있다
        # 2 days

        # 다른 두 날 비교 from()
        const dateA = moment('2021.10.10', 'YYYY-MM-DD');
        const dateB = moment('2020.10.25', 'YYYY-MM-DD');

        console.log(dateA.from(dateB))
        # in a year
        console.log(dateA.from(dateB,true)) # true를 2번째 인자에 넘겨주면 접두사·접미사를 없앨 수 있다
        # a year

        # 차이 값 중 연,월,일 중 제일 큰 단위로 비교해준다
        dateA = 2021.10.10, dateB = 2021.11.25 => a year
        dateA = 2021.10.10, dateB = 2021.11.25 => a month
        dateA = 2021.10.10, dateB = 2021.10.25 => 15 days

        # 다른 두 날 비교 from(), default값은 millisecond 기준이다
        const dateA = moment('2021.10.10', 'YYYY-MM-DD');
        const dateB = moment('2021.11.25', 'YYYY-MM-DD');

        # dateA - dateB
        console.log(dateA.diff(dateB), "millisecond");
        # -35510400000 millisecond
        console.log(dateA.diff(dateB, "days"), "day");
        # -411 day
        console.log(dateA.diff(dateB, "weeks"), "week");
        # -58 week
        console.log(dateA.diff(dateB, "months"), "month");
        # -13 month
        console.log(dateA.diff(dateB, "years"), "year");
        # -1 year
        ```

  - Date Queries

    `Moment.js`는 날짜를 비교하는 다양한 메소드들을 제공하며, 이 메소드들은 이름에서 의미를 알 수 있는 `isBefore()`, `isAfter()`, `isSame()`를 포함하며 이들은 각각 Boolean을 결과로 반환한다. 윤년을 확인하는 `isLeapYear()`함수도 있다

    ```
    console.log(moment('2021.10.11').isAfter('2021.10.13')) # false
    console.log(moment('2021.10.11').isAfter('2020.10.13')) # true
    ```
