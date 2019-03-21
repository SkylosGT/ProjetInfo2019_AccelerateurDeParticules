#include "Element.h"

Element::Element(Vecteur3D _re, Vecteur3D _rs, double _Re, Element const& _suivant)
:vec_re(_re), vec_rs(_rs), scal_Re(_Re), elem_suivant(_suivant)
{}

Element::~Element()
{
}