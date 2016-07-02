// + ======================================== +
// |         gl-oo-interface library          |
// |        Module: GLOO GLUT.                |
// |        Author: Rodrigo Castiel, 2016.    |
// + ======================================== +
//
//  gloo::ViewController is a base class for a
//  view-controller design pattern for any app 
//  using GLUT. The ViewController contains a
//  gloo::ModelBase pointer, which can be used for
//  a derived class of ModelBase. Then, on your 
//  custom application, you should derive Mo-
//  del class and specify its instance to the 
//  ViewController, using SetModel() method.

#pragma once

#include "gl_header.h"

namespace gloo 
{

class ModelBase;  // gloo::ModelBase

class ViewController
{
public:
  ViewController();
  virtual ~ViewController();

  // Sets the gloo::ModelBase to be called on every callback. 
  // By default, ViewController does not own the model,
  // so it means that the ModelBase has to be manually destroyed.
  // If you want ViewController to automatically destroy model,
  // please use the second version of SetModel and specify true. 
  inline void SetModel(class ModelBase* model) { mModel = model; }
  void SetModel(class ModelBase* model, bool ownsModel);

  // Returns the pointer for the current model.
  inline class ModelBase* GetModel() { return mModel; }

  // Tells if ViewController owns the strong reference to ModelBase.
  inline bool OwnsModel() { return mOwnsModel; }

  // Tells if ViewController has a ModelBase* initialized.
  inline bool HasModel() { return mModel != nullptr; }

  // -- Essential Callbacks --
  virtual void Idle();                 // Default callback in each cycle of GLUT.
  virtual void Display();              // Always called before rendering.
  virtual void Reshape(int w, int h);  // Called when the app window is resized.

  // -- Mouse Callbacks --
  virtual void  ActiveMouseMotion(int x, int y);  // When mouse moves when a button is pressed.
  virtual void PassiveMouseMotion(int x, int y);  // When mouse moves without any button pressed.
  virtual void MouseButtonChange(int button, int state, int x, int y);  // When buttons state changes.

  // -- Keyboard Callbacks --
  virtual void KeyboardChange(unsigned char key, int x, int y);         // Called when any key is pressed.
  virtual void SpecialKeyboardChange(unsigned char key, int x, int y);  // Called when special keys are pressed.

protected:
  class ModelBase* mModel { nullptr };
  bool mOwnsModel { false };
};

inline void ViewController::SetModel(class ModelBase* model, bool ownsModel)
{
  mModel = model;
  mOwnsModel = ownsModel;
}

}  // namespace gloo.










