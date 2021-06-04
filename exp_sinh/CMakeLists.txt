set(__PREFIX__ exp_sinh)
set(__PROGS__ zeta)

foreach(name ${__PROGS__})
  set(target_name ${__PREFIX__}_${name})
  add_executable(${target_name} ${name}.cpp)
  set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${name})
endforeach(name)
