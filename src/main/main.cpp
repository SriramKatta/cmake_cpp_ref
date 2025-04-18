#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <iostream>
namespace mpi = boost::mpi;
namespace mt  = mpi::threading;

int main(int argc, char *argv[])
{
  mpi::environment env(argc, argv,mt::funneled);
  if (env.thread_level() < mt::funneled) {
     env.abort(-1);
  }
  mpi::communicator world;
  std::cout << "I am process " << world.rank() << " of " << world.size() << env.processor_name()
            << "." << std::endl;
  return 0;
}