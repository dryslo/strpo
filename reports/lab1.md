# Лабораторная работа №1. Базовая работа с git
### Основные команды Git

Вывод команды `git --help` группирует основные команды по их назначению:

**1. Создание рабочей области:**
* `clone` — клонировать репозиторий в новую директорию.
* `init` — создать пустой репозиторий Git или заново инициализировать существующий.

**2. Работа с текущими изменениями:**
* `add` — добавить содержимое файла в индекс (подготовить к коммиту).
* `mv` — переместить или переименовать файл, директорию или символическую ссылку.
* `restore` — восстановить файлы в рабочей директории.
* `rm` — удалить файлы из рабочей директории и из индекса.

**3. Изучение истории и состояния:**
* `diff` — показать изменения между коммитами, коммитом и рабочей директорией и т.д.
* `log` — показать журналы коммитов.
* `status` — показать состояние рабочего дерева (измененные, добавленные, неотслеживаемые файлы).

**4. Развитие истории:**
* `branch` — список, создание или удаление веток.
* `commit` — записать изменения в репозиторий.
* `merge` — слить две или более историй разработки вместе.
* `switch` — переключиться на другую ветку.

**5. Совместная работа:**
* `fetch` — скачать объекты и ссылки из другого репозитория.
* `pull` — скачать данные из другого репозитория или локальной ветки и интегрировать их.
* `push` — обновить удаленные ссылки и связанные с ними объекты.



## 1. Установка и настройка

**Проверка версии git:**
```
$ git --version
git version 2.43.0
```
**Настройка параметров пользователя:**
```
$ git config --global user.name "Сергей Светличный"
$ git config --global user.email "svetlicjr@gmail.com"
```
**Проверка установки параметров:**
```
$ git config --global -l
user.name=Сергей Светличный
user.email=svetlicjr@gmail.com
```
## 2. Начало работы с новым проектом
**Инициализация git:**
```
$ git init
```

**Создание папки и необходимых файлов:**
```
$ mkdir reports
$ touch README.md
$ touch reports/lab1.md
```
**Проверка создания файлов:**
```
$ tree
.
├── README.md
└── reports
    └── lab1.md

2 directories, 2 files
```
### Основные элементы синтаксиса Markdown

**Markdown** — это облегченный язык разметки текста. Он позволяет форматировать документ с помощью обычных символов, не отвлекаясь от написания кода или текста.

#### Основные синтаксические элементы:

* **Заголовки:** Создаются с помощью символа `#` в начале строки.
  * `# Заголовок первого уровня`
  * `## Заголовок второго уровня`
  * `### Заголовок третьего уровня`

* **Выделение текста:**
  * **Жирный шрифт:** текст оборачивается в двойные звездочки `**текст**`.
  * *Курсив:* текст оборачивается в одинарные звездочки `*текст*`.
  * ***Жирный курсив:*** три звездочки `***текст***`.

* **Списки:**
  * **Маркированные:** создаются с помощью символов `-` или `*` в начале строки.
  * **Нумерованные:** создаются с помощью цифры с точкой, например `1. `, `2. ` и так далее.

* **Оформление кода:**
  * Код внутри строки выделяется одинарными обратными кавычками: `code example`.
  * Блоки кода (многострочные) выделяются тремя обратными кавычками ``` до и после блока.

* **Ссылки:**
  * Оформляются в квадратных и круглых скобках: `[Текст ссылки](https://ссылка.com)`



**Добавление файлов в индекс:**
```
$ git add reports/lab1.md
$ git add README.md
```

**Создание первого коммита:**
```
$ git commit -m "init commit"
[master 5a0cb0a] init commit
 Date: Wed Mar 18 19:14:29 2026 +0300
 2 files changed, 113 insertions(+)
 create mode 100644 README.md      
 create mode 100644 reports/lab1.md
```

## 3. Отслеживание состояния кода

**Команды status и diff:**
* `git status` — показывает текущее состояние рабочей директории и индекса (какие файлы изменены, добавлены или готовы к коммиту).
* `git diff` — показывает конкретные изменения в файлах (разницу между рабочей директорией и индексом или последним коммитом).

```text
$ git status
On branch main
nothing to commit, working tree clean

$ git diff
```
**После переноса заметок в отчет:**
```
$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   reports/lab1.md

no changes added to commit (use "git add" and/or "git commit -a")
```
```
$ git diff
diff --git a/reports/lab1.md b/reports/lab1.md
index 537aa64..0079375 100644
--- a/reports/lab1.md
+++ b/reports/lab1.md
@@ -107,4 +107,25 @@ $ git add README.md
```
Git увидел, что отслеживаемый файл изменен. Поскольку изменения не добавлены в индекс, в status он красный, а diff показывает конкретные добавленные строки.

**Добавление изменений в индекс**
```
$ git add reports/lab1.md
```

```
$ git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   reports/lab1.md
```
Файл отчета перенесен в индекс. Теперь он подготовлен к коммиту.

**Изменения в `README.md`:**
В файле `README.md` была добавлена строка `Изменение в файле readme`
```
$ git diff README.md
diff --git a/README.md b/README.md
index c9aa2c0..78d509a 100644
--- a/README.md
+++ b/README.md
@@ -1,3 +1,4 @@
 # Лабораторные работы по дисциплине "Современные технологии разработки ПО"
 ## *Студент*: Светличный Сергей
-## *Группа*: 5130201/50302
\ No newline at end of file
+## *Группа*: 5130201/50302^M
+Изменение в файле readme
\ No newline at end of file
```
Команда вывела изменения только для одного конкретного файла, игнорируя остальные.

**Коммит только файла отчета:**
```
$ git add reports/lab1.md
$ git commit -m "update lab1 report without readme"
[master 3b7b714] update lab1 report without readme
 1 file changed, 74 insertions(+), 1 deletion(-)
```
Был закоммичен только 1 файл, так как только он находился в индексе. Изменения в `README.md` остались незакоммиченными (остались в рабочей директории).

## 4. Откат изменений

**Проверка изменений в файле `README.md`:**
```
$ git diff --stat README.md
 README.md | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)
```
**Откат изменений в файле `README.md`:**
```
$ git restore README.md
$ cat README.md
# Лабораторные работы по дисциплине "Современные технологии разработки ПО"
## *Студент*: Светличный Сергей
## *Группа*: 5130201/50302
```

**Удаление файла, проверка статуса и восстановление**
```
$ rm reports/lab1.md
$ tree
.
├── README.md        
└── reports

2 directories, 1 file
```
Файл был успешно удален.
```
$ git status
On branch master
Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    reports/lab1.md

no changes added to commit (use "git add" and/or "git commit -a")
```
Git видит, что файл, который он отслеживал, был удален из рабочей директории, но это изменение (само удаление) еще не подготовлено к коммиту.
```
$ git restore reports/lab1.md
$ tree
.
├── README.md
└── reports
    └── lab1.md

2 directories, 2 files
```
Удаленный файл успешно восстановлен в рабочей директории.

## 5. Ветвление версий

**Проверка текущей ветки:**
```
$ git branch
* master
```
**Создание новой ветки и переключение на нее:**
```
$ git checkout -b lab1-1
Switched to a new branch 'lab1-1'
```
**Коммит изменений в новой ветке:**
```
$ git commit -m "add report updates to new branch"
[lab1-1 831c4fa] add report updates to new branch
 1 file changed, 75 insertions(+), 1 deletion(-)
```
**Переключение на изначальную ветку:**
```
$ git checkout master
Switched to branch 'master'
```
После переключения на `master` и проверки файла `reports/lab1.md` выяснилось, что последних добавленных строк в нем нет. Файл вернулся к тому состоянию, в котором он был зафиксирован в последнем коммите ветки `master`. Все новые изменения изолированы в ветке `lab1-1`.
**Попытка переключения ветки с незакоммиченными изменениями:**
В файл `README.md` была добавлена новая строка, но изменения не были закоммичены.
```
$ git checkout lab1-1
M       README.md
Switched to branch 'lab1-1'
```
Git позволил переключиться на другую ветку, несмотря на наличие незакоммиченных изменений в рабочей директории. Буква M перед `README.md` означает, что измененный файл был "перенесен" вместе с нами в ветку `lab1-1`. Это происходит потому, что эти изменения не конфликтуют с файлами в целевой ветке. Если бы был конфликт, Git выдал бы ошибку и прервал переключение, попросив сначала сделать коммит или спрятать изменения (stash).

## 6. Слияние веток, конфликты

**Откат незакоммиченных изменений в файле `README.md`:**
```
$ git restore README.md
```
**Слияние ветки `lab1-1` с основной веткой:**
```
$ git checkout master
$ git merge lab1-1
Updating 3b7b714..831c4fa
Fast-forward
 reports/lab1.md | 76 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
 1 file changed, 75 insertions(+), 1 deletion(-)
```
Git выполнил слияние методом Fast-forward (перемотка вперед), так как основная ветка не имела новых коммитов с момента создания ветки `lab1-1`. Указатель ветки master просто переместился на последний коммит ветки `lab1-1`.

**Изменение заголовка в `README.md` в основной ветке:**
В файле `README.md` заголовок был изменен.
```
$ git add README.md
$ git commit -m "change title in master"
[master 00a8615] change title in master
 1 file changed, 1 insertion(+), 1 deletion(-)
```
**Работа в ветке `lab1-1`:**
```
$ git checkout lab1-1
Switched to branch 'lab1-1'
```
В ветке `lab1-1` были внесены следующие изменения: добавлены новые строки в отчет `reports/lab1.md`, заголовок в `README.md` изменен, и в конец `README.md` добавлена строка `Тестирование конфликтов`.
```
$ git add README.md
$ git add reports/lab1.md
$ git commit -m "update lab1-1 with new title and report data"
[lab1-1 d4fef8e] update lab1-1 with new title and report data
 2 files changed, 48 insertions(+), 2 deletions(-)
```
**Попытка слияния ветки `lab1-1` с `master`:**
```
$ git checkout master
$ git merge lab1-1
Auto-merging README.md
CONFLICT (content): Merge conflict in README.md
Automatic merge failed; fix conflicts and then commit the result.
```
Произошел конфликт слияния (Merge conflict). Git не смог автоматически объединить изменения, так как файл `README.md` был изменен в одном и том же месте (на первой строке с заголовком) в обеих ветках по-разному. Git остановил процесс слияния и просил разрешить конфликт вручную.

Конфликтующие участки выделены маркерами `<<<<<<< HEAD` (текущая ветка master), `=======` (разделитель) и `>>>>>>> lab1-1` (ветка, которую вливаем).
Конфликт был разрешен вручную: служебные маркеры удалены, оставлен итоговый компромиссный вариант заголовка.
```
$ git add README.md
$ git commit -m "Merge branch 'lab1-1' into master, resolve conflict"
[master 628e22b] Merge branch 'lab1-1' into master, resolve conflict
```
**Удаление ветки `lab1-1`:**
```
$ git branch -d lab1-1
Deleted branch lab1-1 (was d4fef8e).
```
## 7. Работа с удаленным репозиторием
На GitHub был создан пустой приватный репозиторий. Для безопасной аутентификации при взаимодействии с удаленным репозиторием был сгенерирован и настроен SSH-ключ.
**Добавление и проверка удаленного репозитория:**
```
$ git remote add origin git@github.com:dryslo/strpo.git
$ git remote -v
origin  git@github.com:dryslo/strpo.git (fetch)
origin  git@github.com:dryslo/strpo.git (push)
```
**Отправка данных в удаленный репозиторий:**
```
$ git push -u origin master
The authenticity of host 'github.com (140.82.121.3)' can't be established.
ED25519 key fingerprint is SHA256:+DiY3wvvV6TuJJhbpZisF/zLDA0zPMSvHdkr4UvCOqU.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'github.com' (ED25519) to the list of known hosts.
Enumerating objects: 22, done.
Counting objects: 100% (22/22), done.
Delta compression using up to 12 threads
Compressing objects: 100% (18/18), done.
Writing objects: 100% (22/22), 5.86 KiB | 117.00 KiB/s, done.
Total 22 (delta 8), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (8/8), done.
To github.com:dryslo/strpo.git
 * [new branch]      master -> master
branch 'master' set up to track 'origin/master'.
```

При обновлении web-страницы созданного репозитория на GitHub отобразились все файлы проекта (`README.md`, папка `reports` с файлом `lab1.md`) и полная история коммитов.

## 8. Синхронизация с удаленным репозиторием
**Клонирование репозитория в новую директорию:**
```
$ cd ..
$ mkdir temp
$ cd temp
$ git clone git@github.com:dryslo/strpo.git
Cloning into 'strpo'...
remote: Enumerating objects: 22, done.
remote: Counting objects: 100% (22/22), done.
remote: Compressing objects: 100% (10/10), done.
remote: Total 22 (delta 8), reused 22 (delta 8), pack-reused 0 (from 0)
Receiving objects: 100% (22/22), 5.86 KiB | 316.00 KiB/s, done.
Resolving deltas: 100% (8/8), done.
```
Копия репозитория успешно скачана. Проверка файлов показала, что структура проекта полностью совпадает с оригиналом на GitHub.

В склонированном репозитории в файл отчета были добавлены текущие шаги, создан коммит и отправлен на сервер с помощью команды `git push`.

```
$ cd strpo
$ git add reports/lab1.md
$ git commit -m "add remote sync protocol"
[master b7e5681] add remote sync protocol
 1 file changed, 87 insertions(+), 1 deletion(-)
$ git push
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 12 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (4/4), 2.52 KiB | 184.00 KiB/s, done.
Total 4 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To github.com:dryslo/strpo.git
   628e22b..b7e5681  master -> master
```
**Возврат в исходный репозиторий и получение обновлений:**
```
$ cd ..
$ cd ..
$ git fetch
remote: Enumerating objects: 7, done.
remote: Counting objects: 100% (7/7), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 4 (delta 1), reused 4 (delta 1), pack-reused 0 (from 0)
Unpacking objects: 100% (4/4), 2.50 KiB | 50.00 KiB/s, done.
From github.com:dryslo/strpo
   628e22b..b7e5681  master     -> origin/master
```
Команда `fetch` обратилась к удаленному репозиторию (`origin`) и скачала информацию о новых коммитах, которых еще нет в локальном репозитории. В данном случае она увидела, что на сервере появился новый коммит от склонированной версии. Важно отметить, что fetch не изменяет рабочую директорию и сами файлы проекта, а лишь скачивает данные и обновляет скрытые указатели (в данном случае `origin`/`master`).

**Синхронизация локальной ветки с удаленной:**
```
$ git pull
Updating 628e22b..b7e5681
Fast-forward
 reports/lab1.md | 88 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
 1 file changed, 87 insertions(+), 1 deletion(-)
```
Команда `git pull` работает как комбинация `git fetch` и `git merge`. Она скачала новые данные и сразу же применила их к текущей локальной ветке методом "перемотки вперед" (Fast-forward). Теперь изначальный локальный репозиторий полностью синхронизирован с удаленным, и в файле отчета появились строки, написанные в другой папке.

## 9. История изменений
**Просмотр истории коммитов (краткий древовидный вид):**
```
$ git log --graph --oneline --all
* b7e5681 (HEAD -> master, origin/master) add remote sync protocol
*   628e22b Merge branch 'lab1-1' into master, resolve conflict
|\
| * d4fef8e update lab1-1 with new title and report data
* | 00a8615 change title in master
|/
* 831c4fa add report updates to new branch
* 3b7b714 update lab1 report without readme
* 5a0cb0a init commit
```