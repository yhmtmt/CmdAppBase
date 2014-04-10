#include <iostream>

using namespace std;

#include "CmdAppBase.h"


// application class should be defined with the base class cmd_app_base
// NOTICE: Don't use this class to the security sensitive application.
// Because, in the current implementation, the library do not check the 
// buffer length of the command line argument. 
class SampleApp: public CmdAppBase
{
private:
  char * fixed_str_arg;
  int fixed_int_arg;
  bool fixed_boolean_arg;
  double fixed_double_arg;
  char * free_str_arg;
  int free_int_arg;
  bool free_boolean_arg;
  double free_double_arg;

public:
  // You need to implement constructor with these arguments, 
  // and initiate base class as in the initialization list.
  SampleApp(int argc, char ** argv):
    CmdAppBase(argc, argv),
    fixed_str_arg(NULL), fixed_int_arg(0), 
    fixed_boolean_arg(false), fixed_double_arg(0.0),
    free_str_arg(NULL), free_int_arg(0),
    free_boolean_arg(false), free_double_arg(0.0)
    
  {
    // Following codes defines the application basic information.
    // These information is printed immediately after execution
    // to the console.
    set_name_app("sample_app");
    set_version(0, 10);
    set_year_copy(2014);
    set_name_coder("Yohei Matsumoto");
    set_contact("matumoto (AT) kaiyodai.ac.jp");
    
    // The arguments defined with the indices is the mandatory arguments.
    // "add_arg" takes two arguments: the first is index of the argument,
    //     and the second is the explanation of the parameter.
    // "add_val" takes two arguments: the first is the pointer to the variable,
    //     and the second is the explanation of the value.
    // "add_val" should  be called immediately after corresponding "add_arg".
    // In this sample, user need to specify the four arguments in the order of 
    // the indices.
    add_arg(1, "String Argument (First Argument)");
    add_val(&fixed_str_arg, "String");
    
    add_arg(2, "Integer Argument (Second Argument)");
    add_val(&fixed_int_arg, "Int");
    
    add_arg(3, "Boolean Argument (Third Argument)");
    add_val(&fixed_boolean_arg, "on or off");

    add_arg(4, "Real Argument (Forth Argument)");
    add_val(&fixed_double_arg, "Real");


    // The arguments defince with the option string is the optional arguments. 
    // User need to specify the arguments with preceding option string,
    // and don't need to care the order of the option in the command line.
    // Notice that the first argument of the add_arg is the option string.
    add_arg("-str", "String Argument 2 (Optional Argument)");
    add_val(&free_str_arg, "String");

    add_arg("-int", "Integer Argument 2 (Optional Argument)");
    add_val(&free_int_arg, "Int");

    add_arg("-bool", "Boolean Argument 2 (Optional Argument)");
    add_val(&free_boolean_arg, "on or off");

    add_arg("-real", "Real Argument 2 (Optional Argument)");
    add_val(&free_double_arg, "Real");
  }

  ~SampleApp(){
  }

  virtual bool main()
  {
    cout << "First argment: " 
	 << fixed_str_arg << endl;
    cout << "Second argument: " 
	 << fixed_int_arg << endl;
    cout << "Third argument: " 
	 << (fixed_boolean_arg ? "on" : "off") << endl;
    cout << "Fourth argument: "
	 << fixed_double_arg << endl;
    cout << "Optional String argument: " 
	 << (free_str_arg  ? free_str_arg : "NULL") << endl;
    cout << "Optional Int argument: " 
	 << free_int_arg << endl;
    cout << "Optional Boolean argument: " 
	 << (free_boolean_arg ? "on" : "off") << endl;
    cout << "Optional Real argument: " 
	 << free_double_arg << endl;
    return true;
  }
};

int main(int argc, char ** argv)
{
  SampleApp app(argc, argv);
  return app.run();
}
