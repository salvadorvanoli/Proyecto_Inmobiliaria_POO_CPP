#ifndef _ICOLLECTIBLE_H
#define	_ICOLLECTIBLE_H

/**
 *  Elemento de la colección
 */
class ICollectible
{
protected:
    /*
     * No se permite instanciar ICollectible directamente
     */
    ICollectible();
public:
    virtual ~ICollectible();
};

#endif	/* _ICOLLECTIBLE_H */

