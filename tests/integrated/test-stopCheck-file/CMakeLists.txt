bout_add_integrated_test(test-stopCheck-file
  SOURCES test_stopCheck.cxx
  USE_RUNTEST
  USE_DATA_BOUT_INP
  EXTRA_FILES
    data/BOUT.stop
    dataSecond/BOUT.inp
    dataSecond/otherStop.check
  )
