// Generated shim: GLES3 stand-in for GL/glcorearb.h (PFN types derived from the functions).
// The renderer is written to the GLES-3-compatible subset, so gl3.h provides every entry point.
#pragma once
#include <GLES3/gl3.h>

typedef decltype(&glGetString) PFNGLGETSTRINGPROC;
typedef decltype(&glGetIntegerv) PFNGLGETINTEGERVPROC;
typedef decltype(&glGetError) PFNGLGETERRORPROC;
typedef decltype(&glClearColor) PFNGLCLEARCOLORPROC;
typedef decltype(&glClear) PFNGLCLEARPROC;
typedef decltype(&glViewport) PFNGLVIEWPORTPROC;
typedef decltype(&glScissor) PFNGLSCISSORPROC;
typedef decltype(&glEnable) PFNGLENABLEPROC;
typedef decltype(&glDisable) PFNGLDISABLEPROC;
typedef decltype(&glDepthFunc) PFNGLDEPTHFUNCPROC;
typedef decltype(&glDepthMask) PFNGLDEPTHMASKPROC;
typedef decltype(&glBlendFunc) PFNGLBLENDFUNCPROC;
typedef decltype(&glBlendFuncSeparate) PFNGLBLENDFUNCSEPARATEPROC;
typedef decltype(&glBlendEquation) PFNGLBLENDEQUATIONPROC;
typedef decltype(&glPixelStorei) PFNGLPIXELSTOREIPROC;
typedef decltype(&glCreateShader) PFNGLCREATESHADERPROC;
typedef decltype(&glShaderSource) PFNGLSHADERSOURCEPROC;
typedef decltype(&glCompileShader) PFNGLCOMPILESHADERPROC;
typedef decltype(&glGetShaderiv) PFNGLGETSHADERIVPROC;
typedef decltype(&glGetShaderInfoLog) PFNGLGETSHADERINFOLOGPROC;
typedef decltype(&glDeleteShader) PFNGLDELETESHADERPROC;
typedef decltype(&glCreateProgram) PFNGLCREATEPROGRAMPROC;
typedef decltype(&glAttachShader) PFNGLATTACHSHADERPROC;
typedef decltype(&glLinkProgram) PFNGLLINKPROGRAMPROC;
typedef decltype(&glGetProgramiv) PFNGLGETPROGRAMIVPROC;
typedef decltype(&glGetProgramInfoLog) PFNGLGETPROGRAMINFOLOGPROC;
typedef decltype(&glDeleteProgram) PFNGLDELETEPROGRAMPROC;
typedef decltype(&glUseProgram) PFNGLUSEPROGRAMPROC;
typedef decltype(&glGetAttribLocation) PFNGLGETATTRIBLOCATIONPROC;
typedef decltype(&glGetUniformLocation) PFNGLGETUNIFORMLOCATIONPROC;
typedef decltype(&glUniformMatrix4fv) PFNGLUNIFORMMATRIX4FVPROC;
typedef decltype(&glUniform1i) PFNGLUNIFORM1IPROC;
typedef decltype(&glGenVertexArrays) PFNGLGENVERTEXARRAYSPROC;
typedef decltype(&glBindVertexArray) PFNGLBINDVERTEXARRAYPROC;
typedef decltype(&glDeleteVertexArrays) PFNGLDELETEVERTEXARRAYSPROC;
typedef decltype(&glGenBuffers) PFNGLGENBUFFERSPROC;
typedef decltype(&glBindBuffer) PFNGLBINDBUFFERPROC;
typedef decltype(&glBufferData) PFNGLBUFFERDATAPROC;
typedef decltype(&glBufferSubData) PFNGLBUFFERSUBDATAPROC;
typedef decltype(&glDeleteBuffers) PFNGLDELETEBUFFERSPROC;
typedef decltype(&glVertexAttribPointer) PFNGLVERTEXATTRIBPOINTERPROC;
typedef decltype(&glEnableVertexAttribArray) PFNGLENABLEVERTEXATTRIBARRAYPROC;
typedef decltype(&glGenTextures) PFNGLGENTEXTURESPROC;
typedef decltype(&glBindTexture) PFNGLBINDTEXTUREPROC;
typedef decltype(&glTexImage2D) PFNGLTEXIMAGE2DPROC;
typedef decltype(&glTexSubImage2D) PFNGLTEXSUBIMAGE2DPROC;
typedef decltype(&glTexParameteri) PFNGLTEXPARAMETERIPROC;
typedef decltype(&glDeleteTextures) PFNGLDELETETEXTURESPROC;
typedef decltype(&glActiveTexture) PFNGLACTIVETEXTUREPROC;
typedef decltype(&glDrawArrays) PFNGLDRAWARRAYSPROC;
typedef decltype(&glReadPixels) PFNGLREADPIXELSPROC;
