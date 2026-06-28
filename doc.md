Генерация ssh-ключа:
ssh-keygen

Задать глобальные настройки git:
git config --global user.name "Denis Zlobin"
git config --global user.email zlobin.d.a@yandex.ru
git config --global core.editor "vim"

Посмотреть глобальные настройки Git:
git config --global --list

Клонировать репозиторий:
git clone <адрес репозитория>

Запросить список всех веток в репозитории:
git branch -a

Создать новую ветку:
git branch имя_ветви

Переключиться на ветку:
git checkout имя_ветви

Проверить текущее состояние репозитория:
git status

Проверить журнал коммитов:
git log

Посмотреть внесенные изменения:
git diff

Индексировать файл для добавления в следующий коммит:
git add имя_файла

Создать коммит:
git commit -m "Сообщение"

Отправить локальные изменения в удаленный репозиторий:
git push -u origin имя_ветви  # при первом push новой ветки
 git push  # для последующих push