# ESP 01S 대기 전류 측정

## 참조 url
https://tasmota.github.io/docs/Energy-Saving/#quantity-measurement-of-esp-12-moduleesp8266-33v-line


## 대상 장치
# 하드웨어
ESP 01S + 릴레이 보드

# 소프트웨어
tasmota 11


## 측정 장치
ETboard + ina219(전류센서보드)


## 측정 결과
sleep 0 -> 대부분 80m
sleep 1 -> 미미
sleep 100 -> 대부분 20mA 이하
sleep 250 -> 대부분 20mA 이하

## 결론
sleep 모드를 적극 사용하면 전력 소모를 1/4 줄일 수 있다.
단, web ui를 접근하지 않고 해야 정확함.
