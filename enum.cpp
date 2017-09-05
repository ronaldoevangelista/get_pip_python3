#include <boost/python.hpp>

char const* yay()
{
  return "Yay!";
}

BOOST_PYTHON_MODULE(libyay)
{
  using namespace boost::python;
  def("yay", yay);
}
/*
int main()
{
   printf("foo");
   return 0;
}
*/