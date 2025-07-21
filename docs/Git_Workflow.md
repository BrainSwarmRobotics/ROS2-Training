# **📌 Git Workflow Guide**

## **🚀 Overview**

Git is a **version control system** that allows multiple developers to collaborate on a project efficiently. This document provides a structured workflow to manage changes, collaborate effectively, and maintain a clean commit history.

## **🔄 Basic Git Workflow Steps**

### **1️⃣ Clone the Repository (First-Time Setup Only)**

If you haven't already cloned the project, do so by running:

```bash
git clone <repository-url>
cd <repository-name>
```

### **2️⃣ Create a New Branch**

Never work directly on the `main` or `master` branch. Instead, create a new branch for each feature or bug fix:

```bash
git checkout -b feature-branch-name
```

### **3️⃣ Make Changes and Test**

- Write or modify code in your branch.
- Ensure your changes work correctly before committing.

### **4️⃣ Stage and Commit Changes**

Once you are satisfied with your changes, add and commit them:

```bash
git add .
git commit -m "Descriptive commit message"
```

### **5️⃣ Push Changes to Remote Repository**

Push your branch to the remote repository on GitHub/GitLab:

```bash
git push origin feature-branch-name
```

### **6️⃣ Create a Pull Request (PR)**

- Go to your repository on GitHub/GitLab.
- Open a **Pull Request** (PR) and select the branch you want to merge into (usually `main` or `develop`).
- Add a meaningful description of your changes.
- Assign reviewers if required.

### **7️⃣ Code Review & Merge**

- Reviewers will provide feedback on your PR.
- If requested, make changes and push them again (`git push origin feature-branch-name`).
- Once approved, merge your branch into the `main` branch.

### **8️⃣ Keep Your Local Repository Updated**

Before starting new work, always sync your local repository with the latest changes:

```bash
git checkout main
git pull origin main
git checkout -b new-feature-branch
```

## **❗ Useful Git Commands**

| **Action**                        | **Command**                          |
| --------------------------------- | ------------------------------------ |
| Clone repository                  | `git clone <repo-url>`               |
| Create a new branch               | `git checkout -b branch-name`        |
| Switch to an existing branch      | `git checkout branch-name`           |
| Stage changes                     | `git add .`                          |
| Commit changes                    | `git commit -m "commit message"`     |
| Push changes                      | `git push origin branch-name`        |
| Fetch and merge latest changes    | git pull origin main                 |
| Merge another branch into current | git merge branch-name                |
| View commit history               | git log --oneline --graph            |
| Revert last commit                | git reset --soft HEAD~1              |
| Delete a local branch             | git branch -d branch-name            |
| Delete a remote branch            | git push origin --delete branch-name |

## **🔍 Best Practices**

- ✅ **Use meaningful branch names** (e.g., `feature/user-authentication` instead of `new-stuff`).
- ✅ **Commit frequently with clear messages** to keep track of changes.
- ✅ **Pull latest changes before pushing** to avoid conflicts.
- ✅ **Use `.gitignore` to prevent committing unnecessary files.**
- ✅ **Write clear Pull Request descriptions** to help reviewers understand changes.



![](../assets/git_workflow.png)