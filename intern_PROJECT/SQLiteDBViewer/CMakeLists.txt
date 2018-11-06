Project(SQLiteDBViewer)

set (CMAKE_CXX_STANDARD 11)

add_executable(SQLiteDBViewer 
	mainwindow.h
	mainwindow.cpp
	secondwindow.h 
	secondwindow.cpp 
	index.png 			# not actual source - just here for information
	resources.qrc
	main.cpp)
