set(__PREFIX__ program_options)
set(__PROGS__ example1)

foreach(name ${__PROGS__})
  set(target_name ${__PREFIX__}_${name})
  add_executable(${target_name} ${name}.cpp)
  set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${name})
  target_link_libraries(${target_name} PRIVATE Boost::program_options)
endforeach(name)
