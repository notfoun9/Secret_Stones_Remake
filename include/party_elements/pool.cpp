#include "game_objects/static_texture.h"
#include <party_elements/pool.h>
#include <party_elements/card.h>

Pool::Pool(Application app)
    : app(app)
{
    for (int i = 0; i < 28; ++i)
    {
        cardsCost1.emplace_back(1, i, app);
    }

    for (int i = 0; i < 19; ++i)
    {
        cardsCost2.emplace_back(2, i, app);
    }

    for (int i = 0; i < 13; ++i)
    {
        cardsCost3.emplace_back(3, i, app);
    }

    for (int i = 0; i < 5; ++i)
    {
        cardsCost5.emplace_back(5, i, app);
    }
}
