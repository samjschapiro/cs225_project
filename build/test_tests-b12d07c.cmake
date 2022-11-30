add_test( [==[LatLong map is correct size]==] /workspaces/cs225/cs225_project/build/test [==[LatLong map is correct size]==]  )
set_tests_properties( [==[LatLong map is correct size]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/cs225_project/build)
add_test( [==[LatLong map outputs latitude (Goroka)]==] /workspaces/cs225/cs225_project/build/test [==[LatLong map outputs latitude (Goroka)]==]  )
set_tests_properties( [==[LatLong map outputs latitude (Goroka)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/cs225_project/build)
add_test( [==[LatLong map outputs longitude (Goroka)]==] /workspaces/cs225/cs225_project/build/test [==[LatLong map outputs longitude (Goroka)]==]  )
set_tests_properties( [==[LatLong map outputs longitude (Goroka)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/cs225_project/build)
add_test( [==[Haversine is correct]==] /workspaces/cs225/cs225_project/build/test [==[Haversine is correct]==]  )
set_tests_properties( [==[Haversine is correct]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/cs225_project/build)
add_test( [==[Adjacent List is correct size]==] /workspaces/cs225/cs225_project/build/test [==[Adjacent List is correct size]==]  )
set_tests_properties( [==[Adjacent List is correct size]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/cs225_project/build)
add_test( [==[All airports retrieved have valid ids]==] /workspaces/cs225/cs225_project/build/test [==[All airports retrieved have valid ids]==]  )
set_tests_properties( [==[All airports retrieved have valid ids]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/cs225_project/build)
set( test_TESTS [==[LatLong map is correct size]==] [==[LatLong map outputs latitude (Goroka)]==] [==[LatLong map outputs longitude (Goroka)]==] [==[Haversine is correct]==] [==[Adjacent List is correct size]==] [==[All airports retrieved have valid ids]==])
