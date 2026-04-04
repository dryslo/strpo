# Лабораторная работа №2. Git Flow, Code Review.

## Подготовка репозитория
### Зачем нужен и как работает файл ```.gitignore```:
Файл ```.gitignore``` сообщает ``Git``, какие файлы и директории в рабочем каталоге не нужно отслеживать и добавлять в репозиторий. Это необходимо, чтобы исключить попадание в историю версий вре́менных файлов, результатов компиляции и сборки проекта, которые только засоряют репозиторий.

### Ход выполнения:
Была создана структура директорий для лабораторных работ (labs/lab1/). Добавлен файл ```.gitignore``` со следующими правилами для исключения папок сборки:
```
labs/*/build/
labs/*/out/
```
## Защита веток
### Как работает защита веток в GitHub:
Защита веток (Branch protection rules) позволяет администраторам репозитория накладывать ограничения на внесение изменений в определенные ветки (например, `main`). Это запрещает разработчикам делать прямой `git push` в защищенную ветку или случайно удалять её. Все изменения должны проходить через механизм Pull Request, что гарантирует проведение код-ревью перед слиянием. Для работы этой функции в бесплатном аккаунте GitHub репозиторий должен быть публичным (Public).

### Ход выполнения:
В настройках репозитория на GitHub (Settings → Branches → Add branch protection rule) была установлена защита для ветки main с включенной опцией Require a pull request before merging.
Проверка запрета прямого пуша:
```bash
echo "test" > test.txt
git add test.txt
git commit -m "Test commit for protected branch"
git push origin master
```
Вывод Git (ошибка из-за сработавшей защиты):
```
remote: Resolving deltas: 100% (1/1), done.
remote: Bypassed rule violations for refs/heads/master:
remote:
remote: - Changes must be made through a pull request.
remote:
```
Откат проверочного коммита и создание ветки для Pull Request:

```bash
git reset --hard HEAD~1
git checkout -b pr-test
echo "pr-test-data" > pr-test.txt
git add pr-test.txt
git commit -m "Add pr-test for PR"
git push -u origin pr-test
```
## Запросы на слияние (Pull Request)

### Ход выполнения:
Через веб-интерфейс GitHub был успешно создан запрос на слияние (Pull Request) из ветки `pr-test` в основную ветку `main`. После проверки PR был принят, и выполнено слияние (Merge pull request).

Синхронизация локального репозитория с обновленной основной веткой:
```bash
git checkout master
git pull origin master
```
