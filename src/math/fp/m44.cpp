//Copyright 2023-Present riplin

#include <has/math/fp/M44.H>

namespace Has::Math
{

m44 m44::Identity(v4(1, 0, 0, 0),
                  v4(0, 1, 0, 0),
                  v4(0, 0, 1, 0),
                  v4(0, 0, 0, 1));

v4 m44::X(1, 0, 0, 0);
v4 m44::Y(0, 1, 0, 0);
v4 m44::Z(0, 0, 1, 0);
v4 m44::W(0, 0, 0, 1);

}
