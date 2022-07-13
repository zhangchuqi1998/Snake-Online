import { createRouter, createWebHistory } from 'vue-router'
import PkIndexView from "../views/pk/PkIndexView"
import RecordIndexView from "../views/record/RecordIndexView"
import LeadingBoardView from "../views/leadingboard/LeadingBoardView"
import UserBotIndexView from "../views/user/bot/BotIndexView"
import NotFound from "../views/error/NotFound"

const routes = [
  {
    path: "/",
    name: "home",
    redirect: "/pk/",
  },
  {
    path: "/pk/",
    name: "pk_index",
    component: PkIndexView,
  },
  {
    path: "/record/",
    name: "record_index",
    component: RecordIndexView,
  },
  {
    path: "/leadingboard/",
    name: "leadingboard_index",
    component: LeadingBoardView,
  },
  {
    path: "/user/bot/",
    name: "user_bot_index",
    component: UserBotIndexView,
  },
  {
    path: "/404/",
    name: "404",
    component: NotFound,
  },
  {
    path: "/:catchAll(.*)",
    name: "other",
    redirect: "/404/",
  }
]


const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router
