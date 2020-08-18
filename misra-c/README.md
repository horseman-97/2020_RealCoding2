# Software Testing

## 20200818

## Testing approach 
<br>
![image](/uploads/561453db654af1336ffdc5888208f897/image.png)

- Static Testing : Program is not executed while testing. <br>
    It is often implicit, like proofreading, plus when programming tools/text editors check source code structure or compilers (pre-compilers) check syntax and data flow as static program analysis.
- Dynamic Testing : It takes place when the program itself is run.<br>
    It may begin before the program is 100% complete in order to test particular sections of code and are applied to discrete functions or modules.
- Black-Box Testing : Testing without seeing source code.<Br>
    One advantage of the black box technique is that no programming knowledge is required. Whatever biases the programmers may have had, the tester likely has a different set and may emphasize different areas of functionality.
- White-Box Testing : Testing while watching the code.<br>
    It can test paths within a unit, paths between units during integration, and between subsystems during a system–level test. 

On today's lecture, the main theorem was static test.

## Static Analysis basis

### Standards and Mission Critical

static test means finding fault without execute the program. The "static analysis" and "static test" are same meaning.<br>
While we done static test, we have a specific standard which handles software error. Comparing the test result and the standard, we can find an error.<br>

Every industrial area(usually it called 'domain') has its standard for software qualify.<br>
Automotibile business has MISRA C/C++, Airlines has DO-178C/JSF, and National Defense domain has DAPA, which stands for the 'Defense Acquisition Program Administration'.<br>
![image](/uploads/cf14a705690e578c00d47e89f391c9ea/image.png)
![image](/uploads/b0dc292aafb9ee37fd30a2fb0aa1a828/image.png)
![image](/uploads/adcae313edf280ce2e51d39f6fcadf93/image.png)

Then why our program should follow this standards?<br>
Those domains' common factor is that they are very sophisticate and critical in our lives. Even a tiny single code collision can makes car accident, air crash, and even blow up whole nuclear silo.<br>
This is `mission critical` concept. A mission-critical task, service, or system is one whose failure or disruption would cause an entire operation or business to grind to a halt. It is indispensable to continuing operations.<br>

To learn about this critical job, we can use a `code inspector` tool. Code inspector is a static test automatical tool which offered by the software testing company, suresoft.<br>
On today's lecture practice, we used misra-c 2012 and the sample code offered by the instructor.<br>

After setup code insepctor, you should set toolchain. I used `gcc4.7.2` compiler.<br>
Today we pick `MISRA C`, which is a guidelines for the C programming, especially the motor industrial domain.


## MISRA C practice

The first test code generates 94 violations.<br>
![image](/uploads/0db13ce68b4ee4fe51b73d9520204971/image.png)

- On the code following MISRA C rules, all functions must have its declaration.
- Function declaration should have same function name, function parameter name, and function type.
    For example, declaration1 and 2 are incorrect, as if these are perfect while real compile.
    The declaration3 is only code follow MISRA C as well.
```
//declaration1
int function(int x);

//declaration2
int function(int);

//declaration3
int function(int a);

//definition
int function(int a){
    int a = 0;
    if (...){
        
    }
    else if(...){
    
    }
    else{
        
    }
    return a;
}
```

![misra-c_function_declaration](/uploads/1300f4659e3aa75356ed96d766e5a157/misra-c_function_declaration.png)
<br>

- It is better that pointer should points the limited type by using `const`. 
    If pointer type variable or paramter are not modified, their base type should be const.

![misra-c_pointer_const_declaration](/uploads/e2f8ac9fde20de10445cf3dac1b4241d/misra-c_pointer_const_declaration.png)
<br>

- If an object used in only a single file, it should be declared as `static`.
    That way, we can prevent the accidential wrong approcach.

![misra-c_static_declaration](/uploads/13d71b6558301621c6c4dbeac180c5dd/misra-c_static_declaration.png)
<br>




### References
1. https://en.wikipedia.org/wiki/Software_testing
2. https://www.suresofttech.com/ko/html/tool/code_static.php
3. https://www.investopedia.com/terms/m/mission-critical.asp