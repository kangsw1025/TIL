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

### 14 日

- Cross Browsing

  브라우저나 플랫폼마다 보여지는 모습이 다른 경우가 많은데, 이러한 차이를 최소화하여 브라우저, 환경에 영향을 최소한으로 받고 해당 웹 서비스를 사용할 수 있게 최적화를 하는 작업

- Babel

  Cross Browsing issue를 해결하기 위해 생겨난 툴로 ES6+ 버전의 자바스크립트나 타입스크립트, JSX 등 다른 언어로 분류되는 언어들에 대해서도 모든 브라우저에서 동작할 수 있도록 호환성을 지켜준다. 바벨은 이렇게 추상화 수준을 유지한 채로 코드를 변화시키는 트랜스파일러 역할을 한다

- Babel 빌드 단계

  1. 파싱(Parsing) : 코드를 읽고 추상 구문 트리(AST)로 변환하는 단계
  2. 변환(Transforming) : 추상 구문 트리를 변경
  3. 출력(Printing) : 변경된 결과물을 출력

  <br>
  바벨은 파싱과 출력을 담당하고 변환은 바벨 플러그인이 담당하며 바벨 플러그인은 바벨이 어떤 코드를 어떻게 변환할 지에 대한 규칙을 나타낸다.   
  플러그인을 매번 일일이 설정하는 건 번거로워 필요한 플러그인들을 목적에 따라 세트로 묶어놓은 경우가 많으며 이러한 세트를 프리셋(preset)이라 한다

- Webpack

  ![webpack](https://user-images.githubusercontent.com/62426665/137299012-0da323cf-6484-4fe4-a876-236e5e9d6263.png)
  오픈 소스 자바스크립트 모듈 번들러로써 여러개로 나누어져 있는 파일들을 하나의 자바스크립트 코드로 압축하고 최적화하는 라이브러리이다

  - 모듈 번들러 장점
    - 여러 파일의 자바스크립트 코드를 압축하여 최적화 할 수 있기 때문에 로딩에 대한 네트워크 비용을 줄일 수 있다
    - 모듈 단위로 개발이 가능하여 가독성과 유지보수가 쉽다
    - 최신 자바스크립트 문법을 지원하지 않는 브라우저에서 사용할 수 있는 코드로 쉽게 변환시켜 준다

- Webpack 주요 4가지 개념

  - 엔트리(Entry)  
    웹팩에서 모든 것은 모듈이다. 자바스크립트, 스타일시트, 이미지 등 모든 것을 자바스크립트 모듈로 로딩해서 사용한다  
    ![webpack-dependency-graph](https://user-images.githubusercontent.com/62426665/137300015-d046d865-7ec7-4347-99af-7b8503768e63.jpg)  
    위 그림처럼 자바스크립트가 로딩하는 모듈이 많아질수록 모듈간의 의존성은 증가하며 의존성 그래프의 시작점을 웹팩에서는 엔트리라고 한다  
    디폴트 값은 `./src/index.js`이다

    ### webpack.config.js

    ```javascript
    module.exports = {
      entry: "./src/index.js",
    };
    ```

  - 아웃풋(Output)  
    엔트리에 설정한 자바스크립트 파일을 시작으로 의존되어 있는 모든 모듈을 하나로 묶고 번들된 결과물을 처리하는데 이때 위치를 `output`에 기록한다

    ### webpack.config.js

    ```js
    module.exports = {
      output: {
        filename: "bundle.js",
        path: "./dist",
      },
    };
    ```

  - 로더(loader)  
    웹팩은 모든 파일을 몯류로 관리하지만 자바스크립트밖에 모른다. 비 자바스크립트 파일을 웹팩이 이해하게끔 변경해야하는데 로더가 그런 역할을 한다  
    로더는 `test`와 `use`키로 구성된 객체로 설정할 수 있다

    - `test` : 변환해야하는 파일 또는 파일들을 식별하는 역할
    - `use` : 변환되어야 하는 파일에 대하여 어떤 로더를 사용해야 하는지 설정

    ### babel-loader

    가장 간단한 예가 바벨이다. ES6에서 ES5로 변환할 때 바벨을 사용할 수 있는데 test에 ES6로 작성한 자바스크립트 파일을 지정하고, use에 이를 변환할 바벨 로더를 설정한다

    ```js
    module.exports = {
      module: {
        rules: [
          {
            test: /\.js$/,
            exclude: "node_moduules",
            use: {
              loader: "babel-loader",
              options: {
                presets: ["env"],
              },
            },
          },
        ],
      },
    };
    ```

    로더를 사용하기 위해서는 노드 패키지로 제공하는 로더를 npm으로 추가해야한다

    ```sh
    npm i --save-dev babel-loader babel-core babel-preset-env
    ```

  - 플러그인(PlugIn)  
    로더가 파일단위로 처리하는 반면 플러그인은 번들된 결과물을 처리한다. 번들된 자바스크립트를 난독화 한다거나 특정 텍스트를 추출하는 용도로 사용할 수 있다

    ### UglifyJsPlugin

    UglifyJsPlugin은 로더로 처리된 자바스크립트 결과물을 난독화 처리하는 플러그인이다. 플러그인을 사용할 때는 웹팩 설정 객체의 `plugins`배열에 추가한다

    ```js
    const webpack = require("webpack");
    module.exports = {
      plugins: [new webpack.optimize.UglifyJsPlugin()],
    };
    ```

- 정리

  웹팩은 기본적으로 모듈 번들러다  
  의존성 그래프에서 엔트리로 그래프의 시작점을 설정하면 웹팩은 모든 자원을 몯류로 로딩한 후 아웃풋으로 묶어준다. 로더로 각 모듈별로 바벨, 사스변환 등을 처리하고 이 결과를 플러그인이 받아 난독화, 텍스트 추출 등의 추가 작업을 한다
