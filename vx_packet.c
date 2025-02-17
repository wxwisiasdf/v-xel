#include <protocol.h>
#include <stddef.h>
#include <stdint.h>

size_t vx_packet_size(uint16_t type) {
  if (type == vx_packet_request) {
    return (sizeof(uint16_t) + 2 * sizeof(uint32_t));
  } else if (type == vx_packet_chunk) {
    return (sizeof(uint16_t) + sizeof(vx_chunk_t));
  } else if (type == vx_packet_place) {
    return (sizeof(uint16_t) + 3 * sizeof(uint32_t) + sizeof(uint8_t));
  } else if (type == vx_packet_welcome || type == vx_packet_bye) {
    return (sizeof(uint16_t) + 20 * sizeof(char));
  } else if (type == vx_packet_update) {
    return (sizeof(uint16_t) + 20 * sizeof(char) + 3 * sizeof(float));
  } else if (type == vx_packet_chat) {
    return (sizeof(uint16_t));
  }
  
  return 0;
}
