/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mgos.h"

static void timer_cb(void *arg) {
  mgos_gpio_toggle(14);
  mgos_gpio_toggle(13);
  mgos_gpio_toggle(12);
  mgos_gpio_toggle(15);
  LOG(LL_INFO,("INPUT: %d, %d, %d, %d",mgos_gpio_read(5),mgos_gpio_read(4),mgos_gpio_read(0),mgos_gpio_read(16)));
  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  /* 创建输入输出IO管理 */
  mgos_gpio_setup_output(14, 0);
  mgos_gpio_setup_output(12, 0);
  mgos_gpio_setup_output(13, 1);
  mgos_gpio_setup_output(15, 1);
  mgos_gpio_setup_input(5, 1);
  mgos_gpio_setup_input(4, 1);
  mgos_gpio_setup_input(0, 1);
  mgos_gpio_setup_input(16, 1);
  mgos_set_timer(1000 /* ms */, MGOS_TIMER_REPEAT, timer_cb, NULL);
  return MGOS_APP_INIT_SUCCESS;
}
