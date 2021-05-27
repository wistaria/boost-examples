set(__PREFIX__ tanh_sinh)
set(__PROGS__ example1 example1_fp50 example1_fp100 example2 example2_nodiv example3 example3_noxc example4 example5 example6)

foreach(name ${__PROGS__})
  set(target_name ${__PREFIX__}_${name})
  add_executable(${target_name} ${name}.cpp)
  set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${name})
endforeach(name)
