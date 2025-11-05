#include "party_elements/field.h"
#include <party_elements/manager.h>
#include <party_elements/card.h>

struct Manager::Elements
{
    static Field* field;
};

Field* Manager::Elements::field = nullptr;

void Manager::InitField(Field* field)
{
    static int singleUseGuard{0};
    assert(0 == singleUseGuard++);

    Manager::Elements::field = field;
}

bool Manager::TryUseCard(const Card &card)
{
    return card.CheckCondition(Elements::field->GetState());
}
