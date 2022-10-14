#include "wizmote.h"

namespace esphome {
namespace wizmote {
void WizMoteListener::on_esp_now_message(esp_now::ESPNowPacket packet) {
  WizMotePacket wizmote = WizMotePacket::build(packet);
  if (wizmote.sequence <= this->last_sequence_ && wizmote.bssid == last_bssid)
    return;

  this->last_bssid = wizmote.bssid;
  this->last_sequence_ = wizmote.sequence;
  this->on_button_->trigger(wizmote);
}
}  // namespace wizmote
}  // namespace esphome
