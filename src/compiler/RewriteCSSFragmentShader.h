//
// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#ifndef COMPILER_REWRITE_CSS_FRAGMENT_SHADER
#define COMPILER_REWRITE_CSS_FRAGMENT_SHADER

#include "GLSLANG/ShaderLang.h"

#include "compiler/RewriteCSSShaderBase.h"
#include "compiler/intermediate.h"
#include "compiler/InfoSink.h"

class TInfoSinkBase;

class RewriteCSSFragmentShader : public RewriteCSSShaderBase {
public:
    RewriteCSSFragmentShader(TIntermNode* treeRoot, TInfoSinkBase& infoSink) : RewriteCSSShaderBase(treeRoot, infoSink) {}
    virtual void rewrite();
    
private:    
    void insertCSSFragColorDeclaration();
    void insertTextureUniform();
    void insertBlendingOp();
    
    //
    // Replaces all instances of kGLFragColor with kCSSGLFragColor.
    //
    class ReplaceGLFragColor : public TIntermTraverser
    {
    public:
        ReplaceGLFragColor() : TIntermTraverser(true, false, false) {}
        virtual void visitSymbol(TIntermSymbol*);
    };
};

#endif  // COMPILER_REWRITE_CSS_FRAGMENT_SHADER
