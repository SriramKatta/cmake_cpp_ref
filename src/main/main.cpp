#include <fmt/format.h>
#include <boost/mpi/communicator.hpp>
#include <boost/mpi/environment.hpp>
#include <iostream>
namespace mpi = boost::mpi;
namespace mt = mpi::threading;

int main(int argc, char *argv[]) {
  mpi::environment env(argc, argv, mt::funneled);
  if (env.thread_level() < mt::funneled) {
    env.abort(-1);
  }
  mpi::communicator world;
  fmt::print("I am Process {} of {} on the host {}\n", world.rank(), world.size(),
             env.processor_name());
  return 0;
}