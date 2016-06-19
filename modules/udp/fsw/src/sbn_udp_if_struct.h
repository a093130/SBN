#ifndef _sbn_udp_if_struct_h_
#define _sbn_udp_if_struct_h_

#include "sbn_constants.h"
#include "sbn_platform_cfg.h"
#include "cfe.h"

#define SBN_UDP_ITEMS_PER_FILE_LINE 3

typedef struct
{
    int NetworkNumber;
    int PeerNumber;
    uint32 Addr;
    int  Port;
} SBN_UDP_Entry_t;

typedef struct
{
    SBN_UDP_Entry_t *EntryPtr;
} SBN_UDP_Peer_t;

typedef struct
{
    int Socket;
    SBN_UDP_Entry_t *EntryPtr;
} SBN_UDP_Host_t;

typedef struct
{
    SBN_UDP_Host_t Host;
    SBN_UDP_Peer_t Peers[SBN_MAX_NETWORK_PEERS];
    int PeerCount;

    char SendBuf[SBN_MAX_MSG_SIZE], RecvBuf[SBN_MAX_MSG_SIZE];
    int RecvSize;
} SBN_UDP_Network_t;

typedef struct
{
    SBN_UDP_Network_t Networks[SBN_MAX_NETWORK_PEERS];
    int NetworkCount;
} SBN_UDP_ModuleData_t;

SBN_UDP_ModuleData_t SBN_UDP_ModuleData;

#endif /* _sbn_udp_if_struct_h_ */
