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
	view/MainWindow.cpp view/LoginDialog.cpp  view/TreeRegions.cpp view/ViewDepartments.cpp view/ViewSites.cpp\
	view/Combo_delegate.cpp  view/Multilist.cpp\
	model/Base_item.cpp model/Item_model.cpp model/Item_factory.cpp \
	model/SortFilterProxyModel.cpp model/Geodata.cpp 

HEADERS += database/Database.h \
	search_module/SM_Session.h search_module/Parser.h search_module/ParserGisLub.h\
	search_module/ParserGeofabrik.h \
	core/Department.h core/Format.h core/Geodata_record.h core/GeodataType.h  core/Language.h\
	core/Log.h core/Usertype.h core/Session.h  \ 
	 core/RecordLang.h core/RecordType.h core/Site.h core/State.h core/Scale.h core/User.h core/Status.h\
	view/MainWindow.h view/LoginDialog.h view/TreeRegions.h view/ViewDepartments.h view/ViewSites.h \
	 view/Multilist.h view/Combo_delegate.h  \
	model/Base_item.h model/Item_model.h model/Item_factory.h \
	model/SortFilterProxyModel.h model/Geodata.h model/Types.h

FORMS +=  view/LoginDialog.ui view/MainWindow.ui \
	view/TreeRegions.ui view/ViewDepartments.ui view/ViewSites.ui