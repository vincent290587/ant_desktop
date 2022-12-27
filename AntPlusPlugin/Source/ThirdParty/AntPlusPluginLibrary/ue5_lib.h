//
// Created by vince on 26/12/2022.
//

#if defined _WIN32 || defined _WIN64
#define EXAMPLELIBRARY_IMPORT __declspec(dllimport)
#elif defined __linux__
#define EXAMPLELIBRARY_IMPORT __attribute__((visibility("default")))
#else
#define EXAMPLELIBRARY_IMPORT
#endif

#ifndef ANT_TEST_UE5_LIB_H
#define ANT_TEST_UE5_LIB_H

#if defined(__cplusplus)
extern "C" {
#endif // defined C++

int getIntPlusPlus(int lastInt);

#if defined(__cplusplus)
}
#endif // defined C++

#endif //ANT_TEST_UE5_LIB_H