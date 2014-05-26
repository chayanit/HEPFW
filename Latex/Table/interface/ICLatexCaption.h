#ifndef LATEX_TABLES_ICLATEXCAPTION
#define LATEX_TABLES_ICLATEXCAPTION

#include "Latex/Core/interface/ICLatexObject.h"

// C++ Included
#include <string>

/***********************************************/
/** \brief LaTeX Caption 
 * 
 * LaTeX caption
 ***********************************************/
class ICLatexCaption : public ICLatexObject {
public:

  ICLatexCaption();
  ICLatexCaption(const char* value);

  void       set(std::string value);
  
  std::string get();
  
  std::string toString();
  
private:

  std::string m_caption; ///< Holds the caption text
  
};

#endif