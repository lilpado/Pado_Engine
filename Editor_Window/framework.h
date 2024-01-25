// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//#include <iostream>

//정적 라이브러리 (대부분의 온라인 게임)
// 
// 장점
// - 시스템 환경이 변해도 어플리케이션에 아무 영향 없다.
// - 컴파일 시 필요한 라이브러리를 적재하기 때문에 이식성이 좋다.
// - 런타임시 외부를 참조할 필요가 없기 때문에 속도가 빠르다.
// 
// 단점
// - 같은 코드를 가진 프로그램이 실행할 경우가 있다면, 
//	 코드가 중복될 수 있으니 그만큼 메모리를 낭비한다.
// - 라이브러리가 변경되면 변경된 라이브러리만 재배포 하면되는 것이 아니라,
//   다시 컴파일 해서 새로 빌드된 버전 전체를 재배포..

//동적 라이브러리
// 
// 장점
// - 메모리 절약
// - 보다 쉽게 업그레이드 해서 배포 가능
// - 서로 다른 프로그램에서 동일한 함수를 호출 가능 (메모리 절약)
// - 프로그램 변경시 라이브러리만 재배포하면 되니까 유지보수 쉽다.
// 
// 단점
// - 외부 의존도가 높기 때문에 이식성이 낮다.
// - 공유 라이브러리를 메모리에 올려놓고, 해당 라이브러리를 
//   찾아서 접근해야되므로 속도가 느리다.


// + 간혹 웹 기반 게임 (모바일) - 게임 하면서 배포가 되는 게임들?
// : 동적 라이브러리 사용.
// - 테스트, 관리하기 어렵다. (빌드에서 문제가 발견 X)
// 
// 배포할 일 없고, 다른 프로그램에서 우리의 라이브러리를 사용할 일 X
// 따라서 이번엔 정적 라이브러리를 쓴다.