#ifndef     _ME_EVENT_H_
#define     _ME_EVENT_H_

typedef struct _IMeEvent    IMeEvent;

IME_EXTERN_C IMeEvent*   IMeEventCreate( uint8_t bInitialState , uint8_t bReSet );

typedef void    (*IMeEventSet)( IMeEvent* pIEvent );
typedef void    (*IMeEventReset)( IMeEvent* pIEvent );
typedef uint8_t (*IMeEventWait)( IMeEvent* pIEvent , uint32_t dwMilliseconds );
typedef void    (*IMeEventDestroy)( IMeEvent* pIEvent );

struct _IMeEvent
{
    IMeEventSet m_pSet;
    IMeEventReset m_pReset;
    IMeEventWait    m_pWait;
    IMeEventDestroy m_pDestroy;
};

#define     CEventCreate(a,b)   IMeEventCreate(a,b)
#define     CEventSet(p)        (p->m_pSet(p))
#define     CEventReset(p)      (p->m_pReset(p))
#define     CEventWait(p,a)     (p->m_pWait(p,a))
#define     CEventDestroy(p)    (p->m_pDestroy(p))

#endif
