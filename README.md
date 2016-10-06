Game Programming with C++ STL
============================
This is a Lecture on 2nd Semester of Senior of Univ.

Chapter 01
----------
Necessary C++ grammar before learning STL<br>
<sub>STL을 학습하기 전 꼭 알아야 할 C++ 문법</sub>

Chapter 02
----------
STL comprehension - Container<br>
<sub>STL의 이해 - 컨테이너</sub>

Chapter 03
----------
STL comprehension - Algorithm<br>
<sub>STL의 이해 - 알고리즘</sub>

Chapter 04
----------
OpenGL - Animation<br>
<sub>OpenGL - 애니메이션</sub>

Chapter 06
----------
OpenGL - Keyframe Interpolation<br>
<sub>OpenGL - 키 프레임 보간법</sub>

**제어점 변경을 통한 곡선 변화**
전역적 제어
- 하나의 제어점을 움직이면 전체 곡선이 변함
지역적 제어(사용자가 선호)
- 하나의 제어점을 움직이면 제어점 근처의 곡선 일부만 변함

삼차 곡선(cubic spline)이 실무에 많이 쓰이며

이를 위해 Catmull-Rom spline 가 쓰임.

Catmull-Rom spline : 좌우 꼭지점의 기울기 값의 평균이 사잇꼭지점의 기울기 값
