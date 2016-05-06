TEMPLATE = app
CONFIG += qt console
QT += core widgets network
QT += sql gui
INCLUDEPATH += core database view search_module model
RESOURCES = view/icons/ViewWindowRes.qrc
SOURCES += database/Database.cpp \
	search_module/SM_Session.cpp search_module/Parser.cpp search_module/ParserGisLub.cpp\
	search_module/ParserGeofabrik.cpp \
	core/main.cpp core/State.cpp core/Scale.cpp core/User.cpp core/Status.cpp core/Session.cpp \
	core/Site.cpp core/Format.cpp core/Geodata_record.cpp core/Usertype.cpp core/Department.cpp\
	core/Log.cpp core/Language.cpp core/RecordLang.cpp core/GeodataType.cpp core/RecordType.cpp\
	core/Organization.cpp \
	view/MainWindow.cpp view/LoginDialog.cpp view/Multilist.cpp\
	view/SearchForm.cpp view/NewSource.cpp view/ViewWindow.cpp  view/Combo_delegate.cpp  \
	model/Base_item.cpp model/Item_model.cpp model/Item_factory.cpp \
	model/SortFilterProxyModel.cpp model/Geodata.cpp 

HEADERS += database/Database.h \
	search_module/SM_Session.h search_module/Parser.h search_module/ParserGisLub.h\
	search_module/ParserGeofabrik.h \
	core/Site.h core/Format.h core/State.h core/Scale.h core/User.h core/Status.h \
	core/Usertype.h core/Session.h core/Geodata_record.h core/Department.h core/Organization.h\ 
	core/Log.h core/Language.h core/RecordLang.h core/GeodataType.h core/RecordType.h\
	view/MainWindow.h view/LoginDialog.h view/Combo_delegate.h  \
	view/SearchForm.h view/NewSource.h view/ViewWindow.h view/Multilist.h\
	model/Base_item.h model/Item_model.h model/Item_factory.h \
	model/SortFilterProxyModel.h model/Geodata.h model/Types.h

FORMS +=  view/LoginDialog.ui view/MainWindow.ui \
	view/SearchForm.ui view/NewSource.ui view/ViewWindow.ui