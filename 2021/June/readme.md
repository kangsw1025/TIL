# Today I Learn
## 목표
* 공부한 내용 기록
* 2문제 이상 알고리즘 문제 풀기

## 6月

### 4日

- JSP(Java Server Page)

    - Java 언어를 기반으로 하는 Server Side 스크립트 언어
    - HTML 코드에 Java 코드를 넣어 동적인 웹 페이지를 생성하는 웹 어플리케이션 도구
    - Servlet를 보완한 스크립트 방식으로 Servlet의 모든 기능을 사용 가능
    - 동작 과정
        1. JSP가 실행되면 WAS는 내부적으로 JSP 파일을 Java Servlet으로 변환
        2. WAS는 이 변환한 Servlet을 동작하여 필요한 기능을 수행
        3. 수행 완료 후 생성된 데이터를 웹 페이지와 함께 클라이언트로 응답
    - 생명주기
        - Servlet 생명주기와 유사하다.   
        ![JSP_life_cycle](../../img/jsp_life_cycle.jpg)
    - 문법
        1. JSP Expression   
            **<%= expression %>**  
            JSP Expression element는 String으로 변환되어 Servlet의 출력에 삽입되며 동적인 페이지를 생성하고 끝에 세미콜론(;)을 붙이지 않는다
        2. JSP Scriptlet   
            **<% code fragment %>**   
            간단한 값이 아닌 복잡한 것을 수행하고자 할 때 사용한다   
            임의의 Java 코드를 삽입할 수 있으며 JSP Scriptlet Tag는 메소드가 아닌 변수만 선언할 수 있다
        3. JSP Declaration   
            **<%! declaration %>**   
            JSP Declaration을 사용하면 Servlet 클래스에 삽입되는 메소드나 필드를 정의할 수 있다
        4. JSP Comment   
            **<%-- comment --%>**   
            주석 기능
        5. JSP Directive   
            **<%@ directive %>**   
            JSP 페이지의 전체적인 구조에 영향을 미친다   
            전체 구조에 대해 WAS에 지시를 내리며 지시어에는 page, include, taglib가 들어간다   
               1. page    
               **<%@ page attribute = "value" %>**   
               - page 지시어는 Container에 명령을 제공하는데 사용된다   
               2. include   
               **<% include file = "relative_url" %>**   
               - include 지시어는 변환 단계에서 다른 외부 파일의 내용을 현재 JSP에 병합하도록 Container에 지시한다   
               - 웹 페이지에서 header와 footer의 구성은 거의 동일하기 때문에 외부에서 형식을 만든 후 include 지시어를 이용하여 main.jsp에 병합한다   
               3. taglib   
               **<% taglib uri = "uri" prefix = "prefixOfTag" %>**   
               - JSP API를 사용하면 HTML 또는 XML 태그처럼 보이는 사용자 정의 태그를 정의할 수 있다   
               - tag library는 사용자가 정의한 동작을 구현한 사용자 정의 태그 집합이다
        6. JSP Action   
            JSP Action XML 구문 안의 구조들을 사용하여 WAS의 동작을 제어한다   
               1. **< jsp:forward >** action   
               - 다른 리소스(JSP, html 또는 Servlet과 같은 정적 페이지)로 요청을 전달하는데 사용한다   
               2. **< jsp:include >** action   
               - 현재 JSP 페이지에 다른 리소스를 포함시키는데 사용한다
               3. **< jsp:useBean >** action   
               - 해당하는 Bean(자바 객체)이 존재하는지 확인하고 없으면 지정된 객체를 생성한다   
               4. **< jsp:setProperty >** action   
               - Bean의 속성을 설정한다   
               5. **< jsp:getProperty >** action   
               - 주어진 속성값을 가져오는데 사용되며 이를 문자열로 변호나하고 동적인 웹 페이지를 생성하는데 해당 내용을 사용할 수 있다
    - 호출 방법 (숫자가 커질수록 복잡한 App 또는 큰 규모의 개발팀이 사용)
        1. Call Java code Directly
            - 모든 Java 코드를 JSP 페이지에 넣는 방식으로 아주 적은 양의 코드에만 적합한 전략
        2. Call Java code indirectly
            - 별도의 utility class를 작성하고 호출하는 데 필요한 Java 코드만 JSP 페이지에 넣는다
        3. Use beans
            - beans로 구조화된 별도의 utility class를 작성한 후 jsp:useBean, jsp:getProperty, jsp:setProperty를 사용하여 uility class를 호출한다
        4. Use the MVC architecture
            - Servlet(Controller)이 요청에 응답하고 적절한 데이터를 검색하여 결과를 beans(Model)에 저장하고 결과를 JSP 페이지(View)로 전달하여 결과를 표시한다
            ![mvc_architecture](../../img/simple-mvc-architecture.jpg)
        5. Use the JSP expression Language
            - shorthand syntax를 이용하여 간단하게 객체 속성에 접근하고 출력한다
            - jsp:useBean, jsp:getProperty, jsp:setProperty를 expression language로 간단하게 표현할 수 있다
            - 일반적으로  beans, MVC 패턴을 함께 사용
        6. Use custom tags
            - tag handler class를 만들고 XML과 같은 사용자 정의 태그를 사용하여 태그 핸들러를 호출한다
        