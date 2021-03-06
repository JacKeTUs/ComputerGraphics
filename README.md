# Курсовой проект по компьютерной графике

В рамках данного курсового проекта разработано программное обеспечение для визуализации движения сочленённых объектов, связанных упругими элементами, в пространстве.
В разработанном продукте для визуализации был использован алгоритм Z-буфера, для визуализации теней был использован упрощённый алгоритм трассировки. При построении изображения были учтены базовые аспекты сцены, такие как, например, освещенность.
Продукт предоставляет удобный инструмент-симулятор с достаточно простым интерфейсом. 
По причине использования средств отображения, написанных вручную с нуля, начиная с отображения отрезка на экране, количество кадров в секунду не превышает 30, хотя этого уже вполне достаточно для отображения непрерывной анимации. Также изображение может запаздывать во время вращения сцены при наличии большого числа моделей или при большой закрашиваемой площади.
Приведённая симуляция не учитывает такие параметры, как трение моделей друг об друга, не учитывает деформацию моделей при возможном их столкновении, не учитывает заряд каждой модели, если он может присутствовать. Обработку вышеперечисленных свойств можно будет добавить в программу в дальнейшем.
У программы есть перспективы развития, такие, как:
*	Перенос вычислений с помощью уже реализованных библиотек на графическую карту.
*	Перенос на другие платформы
*	Общая оптимизация алгоритма растеризации, алгоритма просчёта новых положений
*	Улучшение интерфейса


* [UML диаграмма](https://imgur.com/a/ZJO6g)
* [Скриншот программы](https://imgur.com/a/CTc5v)