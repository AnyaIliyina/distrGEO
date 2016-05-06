#include "item_factory.h"

#include "types.h"
#include "Geodata.h"

BaseItem* ItemFactory::loadFromDb(int type) {
	// Создаем верхний элемент
	BaseItem* item = createNew(type);

	QList<BaseItem*> children = item->loadItemsFromDb();
	
	// Добавляем истинные значения верхнему элементу
	for (int i = 0; i < children.count(); i++)
		
		item->appendChild(children[i]);

	return item;
};

BaseItem* ItemFactory::createNew(int type) {
	switch (type)
	{
	
	case ItemTypes::GeodataType:
		return new Geodata();
	
	default:
		return NULL;
	}
};